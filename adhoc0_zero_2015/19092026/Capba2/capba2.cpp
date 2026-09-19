// Cho vào 2 xâu ký tự S1 và S2 hãy xác định xâu S1 có chứa xâu S2 không. 
// Nếu có ghi “S1 chua xau S2”, ngược lại ghi “S2 khong nam trong S1”
// Bài tập có Ntest
// Không chuỗi nào quá 256 ký tự
// Dữ liệu vào: Từ file “Capba2.inp” có format như sau:
//  + Dòng đầu tiên gồm 1 số nguyên dương NTEST (NTEST <= 100) là số lượng test của bài
//  + Mỗi test là gồm 2 xâu nằm trên 2 dòng khác nhau
//  Dữ liệu ra: Ghi ra các kết quả xác định mối quan hệ 2 xâu

#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  int ntest;
  inputFile >> ntest;

  for (int t = 0; t < ntest; ++t) {
    string s1, s2;
    inputFile >> s1 >> s2;

    if (s1.find(s2) != string::npos) {
      cout << s1 << " chua xau " << s2 << endl;
    } else {
      cout << s2 << " khong nam trong " << s1 << endl;
    }
  }

  inputFile.close();
  return 0;
}