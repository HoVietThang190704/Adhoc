//Viết chương trình vẽ một tam giác cân ngược bằng các dấu ‘*” 
//với chiều cao nhập từ file (chiều cao lớn hơn 1)
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

  if (h <= 1) {
    cout << "Chieu cao phai lon hon 1" << endl;
    return 1;
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < i; j++) {
      cout << " ";
    }
    for (int j = 0; j < 2 * (h - i) - 1; j++) {
      cout << "*";
    }
    cout << endl;
  }

  inputFile.close();
  return 0;
}