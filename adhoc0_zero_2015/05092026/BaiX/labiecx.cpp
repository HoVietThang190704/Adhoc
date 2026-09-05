//Viết chương trình vẽ một con bướm có dạng sau 
//với chiều cao nhập từ file (chiều cao lớn hơn 1 và là số lẻ). 
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  if (!inputFile.is_open()) {
    cout << "Khong the mo file input.txt" << endl;
    return 1;
  }

  int h;
  inputFile >> h;
  if (h <= 1 || h % 2 == 0) {
    cout << "Chieu cao phai lon hon 1 va la so le." << endl;
    return 1;
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < h; j++) {
      if (i <= h / 2) { 
        if (j <= i || j >= h - 1 - i) {
          cout << "*";
        } else {
          cout << " ";
        }
      } else {
        if (j < h - i || j >= i) {
          cout << "*";
        } else {
          cout << " ";
        }
      }
    }
    cout << endl;
  }

  inputFile.close();
  return 0;
}