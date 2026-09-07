//Cho 1 ma trận hình vuông, hãy tính tổng các phần tử của từng cột
//Dữ liệu vào: Từ file “Trunghoc1b.inp” có format như sau:
//  + Bắt đầu là một dòng chứa số n là kích cỡ, tiếp theo là n x n số nguyên của ma trận n hàng, n cột
//In ra màn hình n số mỗi số trên một dòng là tổng từng cột từ 1 đến n của ma trận
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
  int **a = new int*[n];
  for (int i = 0; i < n; i++) {
    a[i] = new int[n];
    for (int j = 0; j < n; j++) {
      inputFile >> a[i][j];
    }
  }

  for (int j = 0; j < n; j++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i][j];
    }
    cout << sum << endl;
  }
  
  inputFile.close();
  return 0;
}
