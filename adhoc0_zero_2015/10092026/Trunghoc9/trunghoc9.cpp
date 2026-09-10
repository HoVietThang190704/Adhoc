// Có n cửa hàng đều kinh doanh trong m tháng (m>5). 
//Doanh thu của từng cửa hàng trong từng tháng được lưu trữ. 
//Một cửa hàng sẽ bị đóng cửa nếu nó có doanh thu giảm liên tiếp trong 3 tháng. Hãy cho biết cửa hàng nào sẽ bị đóng cửa.
// Bài tập có Ntest
// Dữ liệu vào: Từ file “Trunghoc9.inp” có format như sau:
//  + Dòng đầu tiên gồm 1 số nguyên dương NTEST (NTEST <= 100) là số lượng test của bài
//  + Mỗi test là một ma trận, bắt đầu là một dòng chứa số n và m, 
//tiếp theo là n x m số nguyên lần lượt là doanh thu các tháng của từng cửa hàng, mỗi cửa hàng ghi trên 1 dòng
// Dữ liệu ra: Ghi ra danh sách thứ tự các cửa hàng bị đóng cửa, nếu không có cửa hàng nào bị đóng cửa ghi ra 1 số không “0”
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  int ntest;
  inputFile >> ntest;
  for (int t = 0; t < ntest; t++) {
    int n, m;
    inputFile >> n >> m;
    int **matrix = new int*[n];
    for (int i = 0; i < n; i++) {
      matrix[i] = new int[m];
      for (int j = 0; j < m; j++) {
        inputFile >> matrix[i][j];
      }
    }

    bool closed = false;
    for (int i = 0; i < n; i++) {
      int count = 0;
      for (int j = 1; j < m; j++) {
        if (matrix[i][j] < matrix[i][j - 1]) {
          count++;
          if (count == 3) {
            cout << (i + 1) << " ";
            closed = true;
            break;
          }
        } else {
          count = 0;
        }
      }
    }
    if (!closed) {
      cout << "0";
    }
    cout << endl;
  }

  inputFile.close();
  return 0;
}
