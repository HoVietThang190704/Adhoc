//Viết chương trình nhập vào một số nguyên không âm N (N<=7). Hãy tính N!
//Bài tập gồm NTEST
//*Yêu cầu: Viết hàm tính giai thừa
//int giaithua (int x)    // hàm trả về (return) giá trị x!
#include <iostream>
#include <fstream>
using namespace std;

int giaithua(int x) {
  if (x == 0 || x == 1) {
    return 1;
  }
  int result = 1;
  for (int i = 2; i <= x; ++i) {
    result *= i;
  }
  return result;
}

int main() {
  ifstream inputFile("input.txt");
  if (!inputFile.is_open()) {
    cout << "Khong the mo file input.txt" << endl;
    return 1;
  }

  int N;
  inputFile >> N;
  if (N < 0 || N > 7) {
    cout << "Gia tri N khong hop le. Vui long nhap mot so nguyen khong am nho hon hoac bang 7." << endl;
    return 1;
  }

  int result = giaithua(N);
  cout << "Giai thua cua " << N << " la: " << result << endl;
}