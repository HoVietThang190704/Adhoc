// Viết chương trình cho vào một số nguyên n lẻ, 
// xây dựng một ma trận gồm các số từ 1 đến n×n từ trên xuống dưới từ trái qua phải. 
// Ví dụ với n = 3 ta có ma trận kích thước 3 x 3 như sau
// 1 2 3
// 4 5 6
// 7 8 9

// Sau đó với một số m là số nguyên dương lẻ, 
// hãy tìm tổng các phần tử của hình vuông nằm chính giữa hình vuông to có cạnh là m
// Dữ liệu vào: Từ file “Trunghoc14.inp” có format như sau:
//  + Dòng đầu tiên gồm 1 số nguyên dương NTEST (NTEST <= 100) là số lượng test của bài
//  + Mỗi test gồm 1 dòng gồm 2 số n và m (m<=n<=100), m và n đều là số lẻ
// Dữ liệu ra: mỗi test hiện ra một số là tổng các phần tử hình vuông cần tính
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  int ntest;
  inputFile >> ntest;

  for (int i = 0; i < ntest; i++) {
    int n, m;
    inputFile >> n >> m;

    long long sum = 0;
    int start = (n - m) / 2;

    for (int row = start; row < start + m; row++) {
      for (int col = start; col < start + m; col++) {
        sum += (row * n + col + 1);
      }
    }
    cout << sum << endl;
  }

  inputFile.close();
  return 0;
}
