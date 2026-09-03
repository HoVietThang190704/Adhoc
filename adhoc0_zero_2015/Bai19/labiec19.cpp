//Viết chương trình nhập vào 2 số nguyên dương a, b (1<a<=b<=10000) n, sau đó tính tổng các số nguyên tố thuộc đoạn [a..b] 
//Mỗi test hiện ra có bao nhiêu số nguyên tố thuộc đoạn đó và tổng các số nguyên tố đó.
//(Số nguyên tố là số lớn hơn 1 và chỉ chia hết cho 1 và chính nó)
//Bài tập gồm NTEST (NTEST<=100). 
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int isPrime(int n) {
  if (n <= 1) return 0;
  for (int i = 2; i<= sqrt(n); i++) {
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

  int NTEST;
  inputFile >> NTEST;
  int a, b;
  for (int i = 0; i < NTEST; i++) {
    if (!(inputFile >> a >> b)) {
      break;
    }
    int count = 0;
    int sum = 0;
    for (int j = a; j <= b; j++) {
      if (isPrime(j)) {
        count++;
        sum += j;
      }
    }
    cout << count << " so nguyen to, tong = " << sum << endl;
  }
  inputFile.close();
  return 0;
}