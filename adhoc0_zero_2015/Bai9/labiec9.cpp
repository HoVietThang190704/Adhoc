//Viết chương trình nhập vào N số nguyên, tìm số lớn nhất, số nhỏ nhất
//Dữ liệu vào từ file, số đầu tiên là số N (0<N<=100), tiếp theo là N số nguyên
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream fin("labiec9.txt");
  if (!fin) {
    cout << "Khong the mo file!" << endl;
    return 1;
  }

  int N;
  if (!(fin >> N) || N <= 0 || N > 100) {
    cout << "Gia tri N khong hop le!" << endl;
    fin.close();
    return 1;
  }

  int num;
  if (!(fin >> num)) {
    cout << "Khong co so nguyen nao trong file!" << endl;
    fin.close();
    return 1;
  }

  int maxNum = num;
  int minNum = num;

  for (int i = 1; i < N; i++) {
    if (fin >> num) {
      if (num > maxNum) maxNum = num;
      if (num < minNum) minNum = num;
    } else {
      cout << "Khong co du so nguyen trong file!" << endl;
      fin.close();
      return 1;
    }
  }

  cout << "So lon nhat: " << maxNum << endl;
  cout << "So nho nhat: " << minNum << endl;

  fin.close();
  return 0;
}