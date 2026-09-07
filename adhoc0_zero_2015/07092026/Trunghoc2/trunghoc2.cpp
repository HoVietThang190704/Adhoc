//Cho 1 ma trận hình vuông, hãy tìm và ghi ra phần tử lớn nhất, nhỏ nhất. 
//Nếu phần tử lớn nhất bằng phần tử nhỏ nhất, ghi ra một số không “0”
//Bài tập có N test
//Dữ liệu vào: Từ file “Trunghoc2.inp” có format như sau:
// + Dòng đầu tiên gồm 1 số nguyên dương NTEST (NTEST <= 100) là số lượng test của bài
// + Mỗi test là một ma trận, bắt đầu là một dòng chứa số n là kích cỡ, tiếp theo là n x n số nguyên
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  if (!inputFile.is_open()) {
    cout << "Khong the mo file input.txt" << endl;
    return 1;
  }

  int ntest;
  inputFile >> ntest;
  if (ntest <= 0 || ntest > 100) {
    cout << "So luong test khong hop le" << endl;
    return 1;
  }

  for (int test = 0; test < ntest; ++test) {
    int n;
    inputFile >> n;
    if (n <= 0) {
      cout << "Kich co ma tran khong hop le" << endl;
      return 1;
    }

    int maxElement = INT_MIN;
    int minElement = INT_MAX;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int element;
        inputFile >> element;
        if (element > maxElement) {
          maxElement = element;
        }
        if (element < minElement) {
          minElement = element;
        }
      }
    }

    if (maxElement == minElement) {
      cout << "0" << endl;
    } else {
      cout << maxElement << " " << minElement << endl;
    }
  }

  inputFile.close();
  return 0;
}