//Viết chương trình vẽ một tam giác cân rỗng bằng các dấu ‘*” 
//với chiều cao nhập từ file (chiều cao lớn hơn 2)
#include <iostream>
#include <fstream>
using namespace std;

int main () {
  ifstream inputFile("input.txt");
  if (!inputFile.is_open()) {
    cout << "Khong the mo file input." << endl;
    return 1;
  }

  int h;
  inputFile >> h;
  if (h <= 2) {
    cout << "Chieu cao phai lon hon 2." << endl;
    return 1;
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= h - i; j++) {
      cout << " ";
    }
    for (int j = 1; j <= 2 * i - 1; j++) {
      if (j == 1 || j == 2 * i - 1 || i == h) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }

}