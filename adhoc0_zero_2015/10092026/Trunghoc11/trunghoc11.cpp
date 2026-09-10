// Cho 1 ma trận A (n x n), ma trận a được gọi là “đối gương” 
//nếu tất cả các phần tử bằng các phần tử đối xứng với nó qua trục dọc trung tâm. 
//Hãy kiểm tra xem ma trận vừa nhập có đối gương hay không? Nếu đối gương ghi một số 1 và 0 nếu ngược lại
// Bài tập có Ntest
// Dữ liệu vào: Từ file “Trunghoc11.inp” có format như sau:
//  + Dòng đầu tiên gồm 1 số nguyên dương NTEST (NTEST <= 100) là số lượng test của bài
//  + Mỗi test là một ma trận, bắt đầu là một dòng chứa số nguyên dương n là kích cỡ (1 < <=100), tiếp theo là n x n số nguyên
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  int ntest;
  inputFile >> ntest;
  for (int t = 0; t < ntest; t++) {
    int n;
    inputFile >> n;
    int **matrix = new int*[n];
    for (int i = 0; i < n; i++) {
      matrix[i] = new int[n];
      for (int j = 0; j < n; j++) {
        inputFile >> matrix[i][j];
      }
    }

    int isMirror = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n / 2; j++) {
        if (matrix[i][j] != matrix[i][n - j - 1]) {
          isMirror = 0;
          break;
        }
      }
      if (!isMirror) {
        break;
      }
    }
    cout << isMirror << endl;
  }

  inputFile.close();
  return 0;
}