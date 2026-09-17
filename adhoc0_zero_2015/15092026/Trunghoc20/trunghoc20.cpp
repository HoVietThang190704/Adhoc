#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int getRowSum(int r, int c1, int c2, int **prefixRow)
{
  return prefixRow[r][c2] - (c1 > 0 ? prefixRow[r][c1 - 1] : 0);
}

int getDiagSum(int r1, int c1, int r2, int c2, int n, int **prefixDiag)
{
  int sum = prefixDiag[r2][c2];
  if (r1 > 0 && c1 + 1 < n)
  {
    sum -= prefixDiag[r1 - 1][c1 + 1];
  }
  return sum;
}

int main()
{
  ifstream inputFile("input.txt");
  int ntest;
  inputFile >> ntest;

  for (int t = 0; t < ntest; t++)
  {
    int m, n;
    inputFile >> m >> n;

    int **matrix = new int *[m];
    for (int i = 0; i < m; i++)
    {
      matrix[i] = new int[n];
      for (int j = 0; j < n; j++)
      {
        inputFile >> matrix[i][j];
      }
    }

    int **prefixRow = new int *[m];
    for (int i = 0; i < m; i++)
    {
      prefixRow[i] = new int[n];
      prefixRow[i][0] = matrix[i][0];
      for (int j = 1; j < n; j++)
      {
        prefixRow[i][j] = prefixRow[i][j - 1] + matrix[i][j];
      }
    }

    int **prefixDiag = new int *[m];
    for (int i = 0; i < m; i++)
    {
      prefixDiag[i] = new int[n];
      for (int j = 0; j < n; j++)
      {
        prefixDiag[i][j] = matrix[i][j];
        if (i > 0 && j + 1 < n)
        {
          prefixDiag[i][j] += prefixDiag[i - 1][j + 1];
        }
      }
    }

    int countZ = 0;
    for (int size = 3; size <= min(m, n); size++)
    {
      for (int i = 0; i <= m - size; i++)
      {
        for (int j = 0; j <= n - size; j++)
        {
          if (getRowSum(i, j, j + size - 1, prefixRow) != 0) continue;
          if (getRowSum(i + size - 1, j, j + size - 1, prefixRow) != 0) continue;
          if (getDiagSum(i, j + size - 1, i + size - 1, j, n, prefixDiag) != 0) continue;
          countZ++;
        }
      }
    }
    cout << countZ << '\n';
  }
  inputFile.close();
  return 0;
}