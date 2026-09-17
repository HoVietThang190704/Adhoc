// Cho 1 ma trận m x n các số nguyên,
// hãy xác định xem trong số những tam giác cân kích thước đáy là k trong ma trận (k>1; k <= m,n),
// tam giác nào chứa nhiều số nguyên tố nhất
// Dữ liệu vào: Từ file “Trunghoc19.inp” có format như sau:
//  + Dòng đầu tiên gồm 1 số nguyên dương NTEST (NTEST <= 100) là số lượng test của bài
//  + Mỗi test là một ma trận, bắt đầu là một dòng chứa số m, n và k, tiếp theo là m x n số nguyên. (0 < m,n <= 100)
// Dữ liệu ra: mỗi test hiện ra một số là số số nguyên tố lớn nhất mà một tam giác cân kích thước đáy k chứa.
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int isPrime(int n)
{
  if (n <= 1)
    return 0;
  if (n == 2)
    return 1;
  if (n % 2 == 0)
    return 0;
  for (int i = 3; i <= sqrt(n); i += 2)
  {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

int getRowSum(int r, int c1, int c2, int **prefixRowSum)
{
  return prefixRowSum[r][c2] - (c1 > 0 ? prefixRowSum[r][c1 - 1] : 0);
}

int getColSum(int c, int r1, int r2, int **prefixColSum)
{
  return prefixColSum[r2][c] - (r1 > 0 ? prefixColSum[r1 - 1][c] : 0);
}

int main()
{
  ifstream inputFile("input.txt");
  int ntest;
  inputFile >> ntest;

  for (int t = 0; t < ntest; t++)
  {
    int m, n, k;
    inputFile >> m >> n >> k;

    int **matrix = new int *[m];
    for (int i = 0; i < m; i++)
    {
      matrix[i] = new int[n];
      for (int j = 0; j < n; j++)
      {
        inputFile >> matrix[i][j];
      }
    }

    int **prefixRowSum = new int *[m];
    int **prefixColSum = new int *[m];
    for (int i = 0; i < m; i++)
    {
      prefixColSum[i] = new int[n];
      prefixRowSum[i] = new int[n];
      for (int j = 0; j < n; j++)
      {
        int isP = isPrime(matrix[i][j]);
        prefixColSum[i][j] = isP;
        if (i > 0)
          prefixColSum[i][j] += prefixColSum[i - 1][j];
        prefixRowSum[i][j] = isP;
        if (j > 0)
          prefixRowSum[i][j] += prefixRowSum[i][j - 1];
      }
    }

    int h = (k + 1) / 2;
    int offset = (k % 2 == 0) ? 1 : 0;
    int maxPrimes = 0;

    for (int r = 0; r + h - 1 < m; r++)
    {
      for (int c = 0; c < n; c++)
      {
        int leftCol = c - (h - 1);
        int rightCol = c + offset + (h - 1);
        if (leftCol >= 0 && rightCol < n)
        {
          int currentSum = 0;
          for (int d = 0; d < h; d++)
          {
            currentSum += getRowSum(r + d, c - d, c + offset + d, prefixRowSum);
          }
          maxPrimes = max(maxPrimes, currentSum);
        }
      }
    }

    for (int r = h - 1; r < m; r++)
    {
      for (int c = 0; c < n; c++)
      {
        int leftCol = c - (h - 1);
        int rightCol = c + offset + (h - 1);
        if (leftCol >= 0 && rightCol < n)
        {
          int currentSum = 0;
          for (int d = 0; d < h; d++)
          {
            currentSum += getRowSum(r - d, c - d, c + offset + d, prefixRowSum);
          }
          maxPrimes = max(maxPrimes, currentSum);
        }
      }
    }

    for (int c = 0; c + h - 1 < n; c++)
    {
      for (int r = 0; r < m; r++)
      {
        int topRow = r - (h - 1);
        int bottomRow = r + offset + (h - 1);
        if (topRow >= 0 && bottomRow < m)
        {
          int currentSum = 0;
          for (int d = 0; d < h; d++)
          {
            currentSum += getColSum(c + d, r - d, r + offset + d, prefixColSum);
          }
          maxPrimes = max(maxPrimes, currentSum);
        }
      }
    }

    for (int c = h - 1; c < n; c++)
    {
      for (int r = 0; r < m; r++)
      {
        int topRow = r - (h - 1);
        int bottomRow = r + offset + (h - 1);
        if (topRow >= 0 && bottomRow < m)
        {
          int currentSum = 0;
          for (int d = 0; d < h; d++)
          {
            currentSum += getColSum(c - d, r - d, r + offset + d, prefixColSum);
          }
          maxPrimes = max(maxPrimes, currentSum);
        }
      }
    }

    cout << maxPrimes << endl;
  }

  inputFile.close();
  return 0;
}