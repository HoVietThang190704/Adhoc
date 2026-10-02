// Mỗi chuỗi ký tự được gọi là có chu kỳ K nếu nó có thể tạo bởi một 
//hoặc nhiều lần của một chuỗi khác có độ dài K. 
// Ví dụ, chuỗi "abcabcabcabc" có chu kỳ là 3, 
// bởi vì nó có thể tạo được bằng 4 lần chuỗi "abc". 
// Nó cũng có chu kỳ 6 (lặp 2 lần của "abcabc") và 12 (một lần lặp của "abcabcabcabc"). 
// Hãy viết một chương trình đọc vào một chuỗi ký tự và xác định chu kỳ bé nhất của nó 
// Input “peristr.inp”
// Dòng đầu tiên chứa một số nguyên NTEST là số lượng test, sau đó là 1 dòng trắng. 
// Mỗi test bao gồm 1 chuỗi ký tự không quá 80 ký tự. Hai test liên tiếp cách nhau một dòng trắng 
// Output “peristr.out”
// Với mỗi test hiện một số tự nhiên là chu kỳ nhỏ nhất. Giữa 2 kết quả cách nhau một dòng trắng 
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ifstream input("input.txt");
  int NTEST;
  input >> NTEST;

  for (int i = 0; i < NTEST; i++) {
    string s;
    input >> s;
    int len = s.length();

    int minPeriod = len;

    for (int k = 1; k <= len / 2; k++) {
      if (len % k == 0) {
        string sub = s.substr(0, k);
        string repeated = "";
        for (int j = 0; j < len / k; j++) {
          repeated += sub;
        }
        if (repeated == s) {
          minPeriod = k;
          break;
        }
      }
    }
    cout << minPeriod << endl;
  }
}
