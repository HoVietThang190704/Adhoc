//Viết chương trình nhập vào một số nguyên dương không lớn hơn 10000, 
//in ra màn hình tổng các chữ số của nó (ví dụ nhập n= 1356 in ra 15). Bài tập có NTEST
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  if(!inputFile) {
    cerr << "Khong the mo file input.txt" << endl;
    return 1;
  }

  int ntest;
  inputFile >> ntest;
  for(int i = 0; i < ntest; i++) {
    int n;
    inputFile >> n;
    if(n < 1 || n > 10000) {
      cerr << "So nhap vao khong hop le: " << n << endl;
      continue;
    }

    int sum = 0;
    while(n > 0) {
      sum += n % 10;
      n /= 10;
    }
    cout << sum << endl;
  }
}