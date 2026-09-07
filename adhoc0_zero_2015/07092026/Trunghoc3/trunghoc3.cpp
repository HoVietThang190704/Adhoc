//Cho 1 ma trận m x n (m hàng, n cột), hãy tìm số số nguyên tố 
//và tính tổng các số nguyên tố đó (Số nguyên tố là số nguyên dương lớn hơn 1 chỉ chia hết 1 và chính nó)
//Nếu không có số nguyên tố nào, ghi ra một số không “0”
//Bài tập có Ntest
//Dữ liệu vào: Từ file “Trunghoc3.inp” có format như sau:
// + Dòng đầu tiên gồm 1 số nguyên dương NTEST (NTEST <= 100) là số lượng test của bài
// + Mỗi test là một ma trận, bắt đầu là một dòng chứa số nguyên dương m và n (0<m,n<=100) là kích cỡ, 
// // tiếp theo là m x n số nguyên
#include <iostream>
#include <fstream>
using namespace std;

int isPrime(int x) {
  if(x <= 1) return 0;
  if(x == 2) return 1;
  if(x % 2 == 0) return 0;
  for(int i = 3; i * i <= x; i += 2) {
    if(x % i == 0) return 0;
  }
  return 1;
}

int main() {
  ifstream inputFile("input.txt");
  if (!inputFile.is_open()) {
    cout << "Khong the mo file input.txt" << endl;
    return 1;
  }

  int ntest;
  inputFile >> ntest;
  if (ntest <= 0 || ntest > 100) {
    cout << "So luong test khong hop le" << endl;
    return 1;
  }

  for (int t = 0; t < ntest; ++t) {
    int m, n;
    inputFile >> m >> n;
    if (m <= 0 || m > 100 || n <= 0 || n > 100) {
      cout << "Kich co ma tran khong hop le" << endl;
      return 1;
    }

    int primeCount = 0;
    long long primeSum = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int num;
        inputFile >> num;
        if (isPrime(num)) {
          primeCount++;
          primeSum += num;
        }
      }
    }

    if (primeCount == 0) {
      cout << "0" << endl;
    } else {
      cout << primeCount << " " << primeSum << endl;
    }
  }

  inputFile.close();
  return 0;
}
