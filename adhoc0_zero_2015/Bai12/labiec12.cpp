//Viết chương trình nhập vào N số (0<N<100) và kiểm tra xem N số đó có phải là số nguyên tố hay không? 
//Số nguyên tố là số lớn hơn 1 và chỉ chia hết cho 1 và chính nó
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  ifstream inputFile("input.txt");
  if (!inputFile) {
    cout << "Khong the mo file input.txt" << endl;
    return 1;
  }

  int N;
  inputFile >> N;

  if (N <= 0 || N >= 100) {
    cout << "Gia tri N khong hop le. Vui long nhap mot so nguyen duong nho hon 100." << endl;
    return 1;
  }

  for (int i = 0; i < N; i++) {
    int num;
    if (inputFile >> num) {
      cout << num << " la so nguyen to: " << (isPrime(num) ? "Co" : "Khong") << endl;
    } else {
      cout << "Loi: File khong du " << N << " so de doc!" << endl;
      break;
    }
  }

  inputFile.close();
  return 0;
}