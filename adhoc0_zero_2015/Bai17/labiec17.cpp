//Viết chương trình nhập vào N số nguyên (0<N<100) và 
//kiểm tra xem N số đó có phải là số nguyên tố hay không? 
//(Số nguyên tố là số lớn hơn 1 và chỉ chia hết cho 1 và chính nó)
//*Yêu cầu: Viết hàm kiểm tra số nguyên tố theo mẫu int languyento(int x)    
// return 0 neu khong la so nguyen to, return 1 neu la so nguyen to
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int Languyento(int x) {
  if (x < 2) return 0;
  for (int i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) return 0;
  }
  return 1;
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
    cout << "N phai nam trong khoang (0, 100)" << endl;
    return 1;
  }

  for (int i = 0; i < N; i++) {
    int num;
    inputFile >> num;
    if (Languyento(num)) {
      cout << num << " la so nguyen to" << endl;
    } else {
      cout << num << " khong la so nguyen to" << endl;
    }
  }
}