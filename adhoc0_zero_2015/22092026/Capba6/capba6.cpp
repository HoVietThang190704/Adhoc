// Cho vào một xâu ký tự chỉ bao gồm các chữ cái ‘A’ đến ‘Z’ và ‘a’ đến ‘z’. Hãy chuyển xâu đó thành chữ in
// Bài tập có Ntest
// Không chuỗi nào quá 256 ký tự
// Dữ liệu vào: Từ file “Capba6.inp” có format như sau:
//  + Dòng đầu tiên gồm 1 số nguyên dương NTEST (NTEST <= 100) là số lượng test của bài
//  + Mỗi test là gồm 1 chuỗi năm trên 1 dòng khác nhau
//  Dữ liệu ra: Ghi ra chuỗi mới

#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  int ntest;
  inputFile >> ntest;

  for (int t = 0; t < ntest; t++) {
    string str;
    inputFile >> str;

    for (int i = 0; i < str.length(); i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        str[i] = str[i] - 'a' + 'A';
      }
    }
    cout << str << endl;
  }
}