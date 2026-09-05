//Viết chương trình vẽ một chữ X có dạng sau 
//với chiều cao nhập từ file (chiều cao lớn hơn 0 và là số lẻ).
//Đường chéo chính là các ký tự “$” và đường chéo phụ trừ vị trí tâm là ký tự “*”
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  if (!inputFile.is_open()) {
    cerr << "Khong the mo file input.txt" << endl;
    return 1;
  }

  int h;
  inputFile >> h;
  if (h <= 0 || h % 2 == 0) {
    cout << "Chieu cao phai lon hon 0 va la so le." << endl;
    return 1;
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < h; j++) {
      if (i == j) cout << "$";
      else if (i + j == h - 1) cout << "*";
      else cout << " ";
    }
    cout << endl;
  }

  inputFile.close();
  return 0;
}