//Viết chương trình vẽ một chữ T bằng các dấu ‘*” với 
//chiều cao và rộng nhập từ file (chiều rộng là một số lẻ)
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  if (!inputFile) {
    cout << "Khong the mo file input.txt" << endl;
    return 1;
  }

  int h, w;
  inputFile >> h >> w;
  
  if (w % 2 == 0) {
    cout << "Chieu rong phai la mot so le." << endl;
    return 1;
  }

  for (int j = 0; j < w; j++) {
    cout << "*";
  }
  cout << endl;

  for (int i = 0; i < h - 1; i++) {
    for (int j = 0; j < w / 2; j++) {
      cout << " ";
    }
    cout << "*" << endl;
  }

  inputFile.close();
  return 0;
}