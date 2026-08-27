//Viết chương trình vẽ một tam giác cân bằng các dấu ‘*” 
//với chiều cao nhập từ file (chiều cao lớn hơn 1)
#include <iostream>
#include <fstream>

using namespace std;

int main () {
  ifstream fin("labiec7.inp");
  int h;

  if (!fin) {
    cout << "Khong the mo file!" << endl;
    return 1;
  }

  fin >> h;
  fin.close();

  if (h <= 1) {
    cout << "Chieu cao phai lon hon 1!" << endl;
    return 1;
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= h - i; j++) {
      cout << " ";
    }
    for (int j = 1; j <= 2 * i - 1; j++) {
      cout << "*";
    }
    cout << endl;
  }
}