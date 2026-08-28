//Viết chương trình tìm ước số chung lớn nhất 
//và bội số chung nhỏ nhất của 2 số nguyên dương a và b (0<a,b<=100)
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  fstream input("labiec10.txt");
  int a, b;
  input >> a >> b;
  input.close();

  // Tìm ước số chung lớn nhất
  int usc = 1;
  for (int i = 1; i <= min(a, b); i++) {
    if (a % i == 0 && b % i == 0) {
      usc = i;
    }
  }

  // Tìm bội số chung nhỏ nhất
  int bsc = (a * b) / usc;

  // In kết quả
  cout << usc << endl;
  cout << bsc << endl;

  return 0;
}