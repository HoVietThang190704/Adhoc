// Cho 1 ma trận A (n x n), ma trận a được gọi là “hợp lệ” nếu tất cả các phần tử trên đường chéo chính đều bằng 0; 
// các phần tử phía trên đường chéo chính đều dương và các phần tử còn lại đều âm. 
//Hãy kiểm tra xem ma trận vừa nhập có hợp lệ không? Nếu hợp lệ ghi một số 1 và 0 nếu ngược lại
// Đường chéo chính xuất phát từ tọa đô (0,0) đến (n,n)
// Bài tập có Ntest
// Dữ liệu vào: Từ file “Trunghoc6.inp” có format như sau:
//  + Dòng đầu tiên gồm 1 số nguyên dương NTEST (NTEST <= 100) là số lượng test của bài
//  + Mỗi test là một ma trận, bắt đầu là một dòng chứa số n là kích cỡ, tiếp theo là n x n số nguyên
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
  for (int test = 0; test < ntest; ++test) {
    int n;
    inputFile >> n;
    int **matrix = new int*[n];
    for (int i = 0; i < n; ++i) {
      matrix[i] = new int[n];
      for (int j = 0; j < n; ++j) {
        inputFile >> matrix[i][j];
      }
    }

    bool isValid = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j && matrix[i][j] != 0) {
          isValid = false;
          break;
        } else if (i < j && matrix[i][j] <= 0) {
          isValid = false;
          break;
        } else if (i > j && matrix[i][j] >= 0) {
          isValid = false;
          break;
        }
      }
      if (!isValid) {
        break;
      }
    }
    cout << (isValid ? 1 : 0) << endl;
  }

  inputFile.close();
  return 0;
}