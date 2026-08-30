//Viết chương trình vẽ hình chữ nhật rỗng bằng các dấu * với kích cỡ chiều ngang a 
//và chiều dọc b nhập từ file (a và b là số nguyên dương lớn hơn 2)
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream input("input.txt");
  if (!input) {
    cerr << "Không thể mở file input.txt" << endl;
    return 1;
  }

  int a, b;
  input >> a >> b;
  input.close();

  if (a <= 2 || b <= 2) {
    cerr << "Kích thước phải lớn hơn 2" << endl;
    return 1;
  }

  for (int i = 0; i < b; i++) {
    for (int j = 0; j < a; j++) {
      if (i == 0 || i == b - 1 || j == 0 || j == a - 1) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
}