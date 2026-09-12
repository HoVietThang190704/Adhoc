// Chúng ta sẽ kiểm tra một dãy số có các dãy con dạng ``Up" và ``Down" 
// Một dãy con ``Up" sẽ tiếp tục cho đến khi gặp một số bé hơn số liền trước nó. 
//Một dãy con``Down" sẽ tiếp tục cho đến khi gặp một số lớn hơn số liền trước nó
// Một dãy ``Up" có thể được bắt đầu bởi sự kết thúc của dãy ``Down" và ngược lại. 
// Nếu một dãy không thể xác định được dãy ``Up" và ``Down" thì coi như dãy không có dãy “Up” và “Down” nào
// Hãy xác định độ dài trung bình của các dãy “Up” và ``Down" trong dãy số cho trước.
// Input “413.inp”
// Mỗi test ghi trên một dòng, bao gồm ít nhất 1 và không quá 30 số nguyên dương. 
//Mỗi số nguyên dương có ít nhất 1 chữ số và nhiều nhất là 4 chữ số. Dãy được kết thúc bằng 1 số 0. Kết thúc bộ test là một số 0
// Output
// Mỗi test ghi ra 2 số thực, số thứ nhất là độ dài trung bình của dãy con ``Up" 
// rồi đến số thứ 2 là độ dài trung bình của dãy con “Down”, 2 số cách nhau một dấu cách. 
// Kết quả làm tròn đến 6 ký tự phần thập phân
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  int prev;
  while (inputFile >> prev && prev != 0) {
    int upCount = 0, downCount = 0;
    int upLength = 0, downLength = 0;
    bool isUp = false, isDown = false;

    int number;
    while (inputFile >> number && number != 0) {
      if (number > prev) {
        if (!isUp) {
          isUp = true;
          isDown = false;
          upCount++;
        }
        upLength++;
      } else if (number < prev) {
        if (!isDown) {
          isDown = true;
          isUp = false;
          downCount++;
        }
        downLength++;
      } else {
        if (isUp) upLength++;
        if (isDown) downLength++;
      }
      prev = number;
    }
    if (upCount > 0) {
      cout << fixed << setprecision(6) << (double)upLength / upCount << " ";
    } else {
      cout << "0.000000 ";
    }
    if (downCount > 0) {
      cout << fixed << setprecision(6) << (double)downLength / downCount << endl;
    } else {
      cout << "0.000000" << endl;
    }
  } 
}