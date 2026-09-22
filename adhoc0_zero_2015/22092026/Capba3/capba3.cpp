// Cho vào một chuỗi (xâu ký tự) hãy xác định chuỗi đối gương dài nhất nằm trong chuỗi đã cho. 
// Nếu có nhiều chuỗi như vậy có thể chọn bất cứ chuỗi nào
// Chuỗi đối gương là chuỗi viết từ phải sang trái giống viết từ trái sang phải
// Bài tập có Ntest
// Không chuỗi nào quá 256 ký tự
// Dữ liệu vào: Từ file “Capba3.inp” có format như sau:
//  + Dòng đầu tiên gồm 1 số nguyên dương NTEST (NTEST <= 100) là số lượng test của bài
//  + NTEST dòng tiếp theo, mỗi dòng là một chuỗi (không bao gồm ký tự trắng)
// Dữ liệu ra: Mỗi test ghi ra các kết quả một chuỗi đối gương dài nhất
#include <iostream>
#include <fstream>
using namespace std;

string extendAroundCenter(const string& s, int left, int right) {
  while (left >= 0 && right < s.length() && s[left] == s[right]) {
    left--;
    right++;
  }
  return s.substr(left + 1, right - left - 1);
}

int main () {
  ifstream inputFile("input.txt");
  int ntest;
  inputFile >> ntest;

  for (int t = 0; t < ntest; t++) {
    string s;
    inputFile >> s;
    int maxLength = 0;
    string longestPalindrome;

    for (int i = 0; i < s.length(); i++) {
      string palindrome1 = extendAroundCenter(s, i, i);
      if (palindrome1.length() > maxLength) {
        maxLength = palindrome1.length();
        longestPalindrome = palindrome1;
      }

      string palindrome2 = extendAroundCenter(s, i, i + 1);
      if (palindrome2.length() > maxLength) {
        maxLength = palindrome2.length();
        longestPalindrome = palindrome2;
      }
    }
    cout << longestPalindrome << endl;
  }
}