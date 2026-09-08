//Cho 1 ma trận hình vuông, hãy tính tổng các phần tử trên 2 đường chéo chính và 
//tìm phần tử nhỏ nhất trên 2 đường chéo chính đó (ghi đường chéo chính có ô tọa độ 0,0 trước) 
// Bài tập có N test
// Dữ liệu vào: Từ file “Trunghoc4.inp” có format như sau:
//  + Dòng đầu tiên gồm 1 số nguyên dương NTEST (NTEST <= 100) là số lượng test của bài
//  + Mỗi test là một ma trận, bắt đầu là một dòng chứa số n là kích cỡ, tiếp theo là n x n số nguyên
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream fileInput("input.txt");
  if (!fileInput.is_open()) {
    cout << "Khong the mo file input.txt" << endl;
    return 1;
  }

  int ntest;
  fileInput >> ntest;
  for (int test = 0; test < ntest; ++test) {
    int n;
    fileInput >> n;
    int **matrix = new int*[n];
    for (int i = 0; i < n; ++i) {
      matrix[i] = new int[n];
      for (int j = 0; j < n; ++j) {
        fileInput >> matrix[i][j];
      }
    }

    int sum = 0, minElement = matrix[0][0];
    int sum2 = 0, minElement2 = matrix[0][n - 1];

    for (int i = 0; i < n; ++i) {
      sum += matrix[i][i];
      if (matrix[i][i] < minElement) minElement = matrix[i][i];
      sum2 += matrix[i][n - 1 - i];
      if (matrix[i][n - 1 - i] < minElement2) minElement2 = matrix[i][n - 1 - i];
    }
    cout << sum << " " << minElement << " ";
    cout << sum2 << " " << minElement2 << endl;
  }

  fileInput.close();
  return 0;
}