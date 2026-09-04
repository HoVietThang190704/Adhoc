//Viết chương trình vẽ một tam giác cân ngược có dạng sau 
//với chiều cao nhập từ file (chiều cao lớn hơn 1). 
//Để ý là các số hàng sau lớn hơn hàng trước x đơn vị (số x cũng nhập từ file). 
//Dữ liệu cho vào sẽ đảm bảo số lớn nhất của tam giác không vượt quá 9
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  if (!inputFile.is_open()) {
    cout << "Khong the mo file input.txt" << endl;
    return 1;
  }

  int h, x;
  inputFile >> h >> x;

  if (h <= 1) {
    cout << "Chieu cao phai lon hon 1" << endl;
    return 1;
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < i; j++) {
      cout << " ";
    }
    for (int j = 0; j < 2 * (h - i) - 1; j++) {
      cout << (i * x + 1);
    }
    cout << endl;
  }

  inputFile.close();
  return 0;
}