//Nhập vào 2 số nguyên a và b, tìm số lớn nhất. Bài tập gồm NTEST
//*Yêu cầu: Viết hàm return số lớn hơn giữa 2 số
#include <iostream>
#include <fstream>
using namespace std;

int max(int a, int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

int main() {
  ifstream inputFile("input.txt");
  if (!inputFile) {
    cerr << "Khong the mo file input.txt" << endl;
    return 1;
  }
  
  int NTEST;
  inputFile >> NTEST;

  for (int i = 0; i < NTEST; ++i) {
    int a, b;
    inputFile >> a >> b;
    int result = max(a, b);
    cout << "So lon nhat = " << result << endl;
  }
}