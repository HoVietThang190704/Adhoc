// Yêu cầu: Đếm số lượng số 0 cuối cùng của một số là tích của một dãy số cho trước
// Dữ liệu vào: “Zero.inp”
// Dòng đầu tiên là một số nguyên dương NTEST là số lượng test, 
// mỗi test ghi trên một dòng được tổ chức như sau: Số đầu tiên là số lượng phần tử N (0<n<1000) của dãy số, 
// tiếp theo là N số nguyên Ai (|Ai|< 215) 
// Dữ liệu ra: “Zero.out”
// Gồm NTEST số, mỗi số ghi trên một dòng là số lượng số 0 ở cuối tích của các phần tử trong dãy tương ứng đã cho
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

    int count2 = 0;
    int count5 = 0;
    bool hasZero = false;

    for (int i = 0; i < n; i++) {
      int ai;
      inputFile >> ai;
      
      if (ai == 0) {
        hasZero = true;
      } else {
        while (ai % 2 == 0) {
          count2++;
          ai /= 2;
        }
        while (ai % 5 == 0) {
          count5++;
          ai /= 5;
        }
      }
    }
    if (hasZero) {
      cout << 1 << endl;
    } else {
      cout << min(count2, count5) << endl;
    }
  }
  
  inputFile.close();
  return 0;
}