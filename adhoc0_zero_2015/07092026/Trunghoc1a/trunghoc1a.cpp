//Cho 1 ma trận hình vuông, hãy tính tổng các phần tử của từng hàng
//Dữ liệu vào: Từ file “Trunghoc1a.inp” có format như sau:
//  + Bắt đầu là một dòng chứa số n là kích cỡ, tiếp theo là n x n số nguyên của ma trận n hàng, n cột
//In ra màn hình n số mỗi số trên một dòng là tổng từng hàng từ 1 đến n của ma trận
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  if (!inputFile.is_open()) {
    cout << "Khong the mo file input.txt" << endl;
    return 1;
  }

  int n;
  inputFile >> n;
  int **matrix = new int*[n];
  for (int i = 0; i < n; i++) {
    matrix[i] = new int[n];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      inputFile >> matrix[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    long long sum = 0;
    for (int j = 0; j < n; j++) {
      sum += matrix[i][j];
    }
    cout << sum << endl;
  }

  inputFile.close();
  return 0;
}
