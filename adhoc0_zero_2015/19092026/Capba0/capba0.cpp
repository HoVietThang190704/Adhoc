// Cho vào 2 xâu ký tự S1 và S2 hãy xác định S1 có giống S2 không, nếu giống ghi 1 số 1, nếu không ghi ra một số 0
// Bài tập có Ntest
// Không chuỗi nào quá 256 ký tự
// Dữ liệu vào: Từ file “Capba0.inp” có format như sau:
//  + Dòng đầu tiên gồm 1 số nguyên dương NTEST (NTEST <= 100) là số lượng test của bài
//  + Mỗi test là gồm 2 xâu cách nhau một khoảng trắng (2 xâu đều không chứa khoảng trắng)
//  Dữ liệu ra: Ghi ra kết quả so sánh 2 xâu
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  int ntest;
  inputFile >> ntest;
  for (int i = 0; i < ntest; i++) {
    string s1, s2;
    inputFile >> s1 >> s2;
    if (s1 == s2) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
  }
  inputFile.close();
  return 0;
}
