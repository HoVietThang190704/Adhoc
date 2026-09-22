// Cho vào 2 xâu ký tự S1 và S2 hãy đếm số lần S1 xuất hiện trong S2
// Bài tập có Ntest
// Không chuỗi nào quá 300 ký tự
// Dữ liệu vào: Từ file “Capba5.inp” có format như sau:
//  + Dòng đầu tiên gồm 1 số nguyên dương NTEST (NTEST <= 100) là số lượng test của bài
//  + Mỗi test là gồm 2 xâu nằm trên 2 dòng khác nhau
//  Dữ liệu ra: Ghi ra số lần S1 xuất hiện trong S2

#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  int ntest;
  inputFile >> ntest;

  for (int t = 0; t < ntest; t++) {
    string s1, s2;
    inputFile >> s1 >> s2;
    int count = 0;

    size_t pos = s2.find(s1);
    while (pos != string::npos) {
      count++;
      pos = s2.find(s1, pos + 1);
    }
    cout << count << endl;
  }
}