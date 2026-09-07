//Cho 1 ma trận hình vuông, hãy đảo ngược ma trận và in ra, cách thức đảo ngược xem test ví dưới đây
//Dữ liệu vào: Từ file “Trunghoc1c.inp” có format như sau:
//  + Dòng đấu tiên chứa một số nguyên dương là số lượng test. 
//  + Mỗi test bắt đầu là một dòng chứa số n là kích cỡ, tiếp theo là n x n số nguyên của ma trận n hàng, n cột
//Dữ liệu ra: in ra các ma trận đảo ngược, các ma trận cách nhau một dòng trắng.
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  if(!inputFile.is_open()) {
    cout << "Khong the mo file input.txt" << endl;
    return 1;
  }

  int ntest;
  inputFile >> ntest;
  if (ntest <= 0) {
    cout << "So luong test phai la so nguyen duong." << endl;
    return 1;
  }

  for (int test = 0; test < ntest; ++test) {
    int n;
    inputFile >> n;
    if (n <= 0) {
      cout << "Kich co ma tran phai la so nguyen duong." << endl;
      return 1;
    }

    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i) {
      matrix[i] = new int[n];
      for (int j = 0; j < n; ++j) {
        inputFile >> matrix[i][j];
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = n - 1; j >= 0; --j) {
        cout << matrix[i][j] << " ";
      }
      cout << endl;
    }

    cout << endl;
  }

  inputFile.close();
  return 0;
}