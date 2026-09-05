//Viết chương trình vẽ một chữ H bằng các dấu ‘*” 
//với chiều cao và rộng nhập từ file 
//(chiều cao là một số lẻ, chiều rộng lớn hơn 2)
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  if (!inputFile.is_open()) {
    cout << "Khong the mo file input.txt" << endl;
    return 1;
  }

  int h, w;
  inputFile >> h >> w;
  if (h % 2 == 0 || w < 2) {
    cout << "Chieu cao phai la so le va chieu rong phai lon hon 2" << endl;
    return 1;
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (j == 0 || j == w - 1 || i == h / 2) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
}