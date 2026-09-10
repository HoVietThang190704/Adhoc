// Viết chương trình hiển thị tháp PASCAL như sau, 
// với số một số n nguyên dương nhập vào từ file “Trunghoc10.inp” là số dòng của tam giác:
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  int n;
  inputFile >> n;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cout << j;
    }
    for (int j = i - 1; j >= 1; j--) {
      cout << j;
    }
    cout << endl;
  }

  inputFile.close();
  return 0;
}