//Viết chương trình vẽ một chữ M 
//bằng các dấu ‘*” với chiều cao là một số lẻ lớn hơn 4
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
  if (h <= 4 || h % 2 == 0) {
    cout << "Chieu cao phai la mot so le lon hon 4" << endl;
    return 1;
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < h; j++) {
      if (j == 0 || j == h - 1 || (i <= h / 2 && j == i) || (i <= h / 2 && j == h - 1 - i)) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
}