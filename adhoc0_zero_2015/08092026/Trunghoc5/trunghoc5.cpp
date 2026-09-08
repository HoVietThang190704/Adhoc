// Cho 1 ma trận m x n (m hàng, n cột), hãy tìm số nguyên tố lớn nhất và 
//đếm số lần xuất hiện của số nguyên tố lớn nhất đó trong ma trận
// Số nguyên tố là số nguyên dương lớn hơn 1 chỉ chia hết 1 và chính nó
// Nếu không có số nguyên tố nào, ghi ra một số không “0”
// Bài tập có Ntest
// Dữ liệu vào: Từ file “Trunghoc5.inp” có format như sau:
//  + Dòng đầu tiên gồm 1 số nguyên dương NTEST (NTEST <= 100) là số lượng test của bài
//  + Mỗi test là một ma trận, bắt đầu là một dòng chứa số nguyên dương m và n (0<m,n<=100) 
//là kích cỡ, tiếp theo là m x n số nguyên
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int isPrime(int n) {
  if (n <= 1) return 0;
  if (n == 2) return 1;
  if (n % 2 == 0) return 0;
  for (int i = 3; i <= sqrt(n); i += 2) {
    if (n % i == 0) return 0;
  }
  return 1;
}

int main() {
  ifstream inputFile("input.txt");
  if (!inputFile.is_open()) {
    cout << "Khong the mo file." << endl;
    return 1;
  }

  int ntest;
  inputFile >> ntest;
  for (int test = 0; test < ntest; ++test) {
    int m, n;
    inputFile >> m >> n;
    int maxPrime = -1;
    int countMaxPrime = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int num;
        inputFile >> num;
        if (isPrime(num)) {
          if (num > maxPrime) {
            maxPrime = num;
            countMaxPrime = 1;
          } else if (num == maxPrime) {
            countMaxPrime++;
          }
        }
      }
    }
    if (maxPrime == -1) {
      cout << "0" << endl;
    } else {
      cout << maxPrime << " " << countMaxPrime << endl;
    }
  }

  inputFile.close();
  return 0;
}
