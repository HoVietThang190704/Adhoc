// Cho vào ba chuỗi (xâu ký tự) S, S1, S2 hãy tìm trong chuỗi S chuỗi S1 và đổi S1 thành S2
// Bài tập có Ntest
// Không chuỗi nào quá 256 ký tự
// Dữ liệu vào: Từ file “Capba4.inp” có format như sau:
//  + Dòng đầu tiên gồm 1 số nguyên dương NTEST (NTEST <= 100) là số lượng test của bài
//  + Mỗi test gồm 3 chuỗi S, S1, S2 trên một dòng cách nhau một khoảng trắng (các chuỗi không bao gồm ký tự trắng)
// Dữ liệu ra: Mỗi test ghi ra chuỗi S mới trên một dòng, giữa các test là một dòng trắng
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  int ntest;
  inputFile >> ntest;

  for (int t = 0; t < ntest; ++t) {
    string S, S1, S2;
    inputFile >> S >> S1 >> S2;

    size_t pos = S.find(S1);
    while (pos != string::npos) {
      S.replace(pos, S1.length(), S2);
      pos = S.find(S1, pos + S2.length());
    };

    cout << S << endl;
  }
}