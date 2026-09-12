// Cho 1 ma trận nhị phân A, hãy đếm số tam giác cân hoàn hảo khác nhau. 
// Tam giác cân hoàn hảo là tam giác cân có tất cả các phần tử bằng 0, 
// đỉnh hướng lên trên và kích thước đáy lớn hơn hoặc bằng 3
// Bài tập có Ntest
// Dữ liệu vào: Từ file “Trunghoc15.inp” có format như sau:
//  + Dòng đầu tiên gồm 1 số nguyên dương NTEST (NTEST <= 100) là số lượng test của bài
//  + Mỗi test là một ma trận, bắt đầu là một dòng chứa số m và n là kích cỡ, tiếp theo là m x n số nguyên. (0 < m,n <= 100)
// Dữ liệu ra: mỗi test hiện ra một số là số tam giác cân hoàn hảo cần tính
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  int ntest;
  inputFile >> ntest;

  for (int t = 0; t < ntest; t++) {
    int m, n;
    inputFile >> m >> n;
    int **matrix = new int*[m];
    for (int i = 0; i < m; i++) {
      matrix[i] = new int[n];
      for (int j = 0; j < n; j++) {
        inputFile >> matrix[i][j];
      }
    }

    int count = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] != 0) continue;
        int k = 1;
        while (true) {
          int row = i + k;
          int colStart = j - k;
          int colEnd = j + k;

          if (row >= m || colStart < 0 || colEnd >= n) break;

          bool validBase = true;
          for (int col = colStart; col <= colEnd; col++) {
            if (matrix[row][col] != 0) {
              validBase = false;
              break;
            }
          }

        if (!validBase) break;
          count++;
          k++;
        }
      }
    }
    cout << count << endl;
  }
  inputFile.close();
  return 0;
}