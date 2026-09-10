// Cho 1 ma trận A (n x n), ma trận a được gọi là “đối xứng” 
//nếu tất cả các phần tử bằng các phần tử đối xứng với nó qua đường chéo chính. 
//Hãy kiểm tra xem ma trận vừa nhập có đối xứng hay không? Nếu đối xứng ghi một số 1 và 0 nếu ngược lại
// Đường chéo chính xuất phát từ tọa độ (0,0) đến (n,n)
// Bài tập có Ntest
// Dữ liệu vào: Từ file “Trunghoc12.inp” có format như sau:
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

    bool isSymmetric = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] != matrix[j][i]) {
          isSymmetric = false;
          break;
        }
      }
      if (!isSymmetric) {
        break;
      }
    }

    cout << (isSymmetric ? 1 : 0) << endl;
  }

  inputFile.close();
  return 0;
}
