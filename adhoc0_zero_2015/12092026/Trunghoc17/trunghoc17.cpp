// Cho 1 ma trận nhị phân kích thước m x n, hãy đếm số chữ T có kích thước t
// (chiều rộng và cao đều là t) tạo bởi các số 1 trong ma trận.
// Bài tập có Ntest
// Dữ liệu vào: Từ file “Trunghoc17.inp” có format như sau:
//  + Dòng đầu tiên gồm 1 số nguyên dương NTEST (NTEST <= 100) là số lượng test của bài
//  + Mỗi test là một ma trận, bắt đầu là một dòng chứa số m, n, t là kích cỡ ma trận và chữ T,
// tiếp theo là m x n số nguyên. (0 < m,n <= 100). Dữ liệu vào đảm bảo t là số lẻ lớn hơn 1
// Dữ liệu ra: mỗi test hiện ra một số là số chữ T cần đếm.
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream inputFile("input.txt");
  int ntest;
  inputFile >> ntest;

  for (int test = 0; test < ntest; test++)
  {
    int m, n, t;
    inputFile >> m >> n >> t;
    int **matrix = new int *[n];
    for (int i = 0; i < m; i++)
    {
      matrix[i] = new int[m];
      for (int j = 0; j < n; j++)
      {
        inputFile >> matrix[i][j];
      }
    }

    if (t > m || t > n)
    {
      cout << 0 << "\n";
      continue;
    }

    int count = 0;
    for (int r = 0; r <= m - t; r++)
    {
      for (int c = 0; c <= n - t; c++)
      {
        int mid_r = r + t / 2;
        int mid_c = c + t / 2;

        bool valid[4] = {true, true, true, true};
        for (int k = 0; k < t; k++)
        {
          if (matrix[r][c + k] == 0 || matrix[r + k][mid_c] == 0)
            valid[0] = false;

          if (matrix[r + t - 1][c + k] == 0 || matrix[r + k][mid_c] == 0)
            valid[1] = false;

          if (matrix[r + k][c] == 0 || matrix[mid_r][c + k] == 0)
            valid[2] = false;

          if (matrix[r + k][c + t - 1] == 0 || matrix[mid_r][c + k] == 0)
            valid[3] = false;
        }
        count += valid[0] + valid[1] + valid[2] + valid[3];
      }
    }
    cout << count << "\n";
  }
  inputFile.close();
  return 0;
}