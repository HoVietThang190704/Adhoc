// Cho vào một chuỗi (xâu ký tự) hãy xác định chuỗi đó có đối gương hay không. Nếu có ghi một số 1, ngược lại ghi 0
// Chuỗi đối gương là chuỗi viết từ phải sang trái giống viết từ trái sang phải
// Bài tập có Ntest
// Không chuỗi nào quá 256 ký tự
// Dữ liệu vào: Từ file “Capba1.inp” có format như sau:
//  + Dòng đầu tiên gồm 1 số nguyên dương NTEST (NTEST <= 100) là số lượng test của bài
//  + Mỗi test là một chuỗi (không bao gồm ký tự trắng)
//  Dữ liệu ra: Ghi ra các kết quả xác định chuỗi có đối gương hay không trên một dòng
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  int ntest;
  inputFile >> ntest;

  for (int i = 0; i < ntest; i++) {
    string str;
    inputFile >> str;
    bool isPalindrome = true;

    int len = str.length();
    for (int j = 0; j < len / 2; j++) {
      if (str[j] != str[len - j - 1]) {
        isPalindrome = false;
        break;
      }
    }
    if (isPalindrome) {
      cout << "1 ";
    } else {
      cout << "0 ";
    }
  }
}
