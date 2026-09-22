// Cho vào một số chuỗi, hãy xác định chuỗi nào chứa nhiều nhất các ký tự khác nhau
// Bài tập có Ntest
// Không chuỗi nào quá 256 ký tự
// Dữ liệu vào: Từ file “Capba7.inp” có format như sau:
//  - Dòng đầu tiên gồm 1 số nguyên dương NTEST (NTEST <= 100) là số lượng test của bài
//  - Mỗi test có bố cục như sau: 
//    + Dòng đầu tiên là một số nguyên dương N (N<100) là số chuỗi
//    + N dòng tiếp theo lần lượt là các chuỗi
//  Dữ liệu ra: Ghi ra chuỗi có số lượng ký tự khác nhau nhiều nhất đó, 
//  tiếp theo là một ký tự trắng và một số là số lượng ký tự khác nhau của nó, 
//  nếu có nhiều chuỗi như vậy có thể in ra bất cứ chuỗi nào
#include <iostream> 
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  int ntest;
  inputFile >> ntest;

  for (int t = 0; t < ntest; t++) {
    int n;
    inputFile >> n;
    string maxString;
    int maxUniqueCount = 0;
    for (int i = 0; i < n; i++) {
      string s;
      inputFile >> s;
      size_t max_distinct = 0;
      string best_str = "";
      for (int j = 0; j < s.length(); j++) {
        if (best_str.find(s[j]) == string::npos) {
          best_str += s[j];
          max_distinct++;
        }
      }
      if (max_distinct > maxUniqueCount) {
        maxUniqueCount = max_distinct;
        maxString = s;
      }
    }
    cout << maxString << " " << maxUniqueCount << endl;
  }
  inputFile.close();
  return 0;
}