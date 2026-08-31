//Cho vào một số nguyên dương N (N<=100), hãy viết tất cả các cặp số nguyên a và b sao cho a + b = N với a > b.
//Ouput: dòng đầu ghi số lượng cặp số tìm được và tiếp theo là các cặp số a, b
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  if (!inputFile.is_open()) {
    cerr << "Khong the mo file input." << endl;
    return 1;
  }

  int N;
  inputFile >> N;
  if (N <= 0 || N > 100) {
    cout << "Gia tri N khong hop le. Vui long nhap mot so nguyen duong nho hon 100." << endl;
    return 1;
  }

  int count = 0;
  for (int a = 0; a <= N; a++) {
    int b = N - a;
    if (a > b && b > 0) {
      count++;
    }
  }
  cout << count << endl;

  for (int a = 0; a <= N; a++) {
    int b = N - a;
    if (a > b && b > 0) {
      cout << a << " " << b << endl;
    }
  }
}