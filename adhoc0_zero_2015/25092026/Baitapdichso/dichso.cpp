// Một công ty Bưu chính cần một phần mềm hóa đơn, trong đó cần chuyển từ dạng số sang chữ. 
// Công ty phần mềm của bạn được thuê làm dự án này, hãy viết chương trình nhập vào một số nguyên dương A (A<1000). 
// Hiện ra mô tả bằng chữ giá trị số A
// Bài tập có N test.
#include <iostream>
#include <fstream>
using namespace std;

string one[] = {"khong", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin"};
string two[] = {"khong", "muoi", "hai muoi", "ba muoi", "bon muoi", "nam muoi", "sau muoi", "bay muoi", "tam muoi", "chin muoi"};
string three[] = {"khong", "mot tram", "hai tram", "ba tram", "bon tram", "nam tram", "sau tram", "bay tram", "tam tram", "chin tram"};

int main() {
  ifstream inputFile("input.txt");
  int ntest;
  inputFile >> ntest;
  for (int i = 0; i < ntest; i++) {
    int A;
    inputFile >> A;

    int tram = A / 100;;
    int chuc = (A / 10) % 10;
    int donvi = A % 10;

    bool hasOutput = false;

    if (tram > 0) {
      cout << three[tram] << " ";
      hasOutput = true;
    }

    if (chuc > 0) {
      if (hasOutput) cout << " ";
      if (chuc == 1) {
        cout << "muoi";
      } else {
        cout << two[chuc];
      }
      hasOutput = true;
    } else if (tram > 0 && donvi > 0) {
      if (hasOutput) cout << " ";
      cout << "linh";
      hasOutput = true;
    }

    if (donvi > 0) {
      if (hasOutput) cout << " ";
      cout << one[donvi];
    }
    cout << endl;
  }
}