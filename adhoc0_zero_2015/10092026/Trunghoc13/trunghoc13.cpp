// Viết chương trình đọc n số nguyên, tìm dãy số liên tiếp các phần tử là dãy tăng dài nhất. 
// Nếu có nhiều dãy như vậy chọn dãy có tổng các giá trị phần tử lớn nhất
// Dữ liệu vào: Từ file “Trunghoc13.inp” có format như sau:
//  + Dòng đầu tiên gồm 1 số nguyên dương NTEST (NTEST <= 100) là số lượng test của bài
//  + Mỗi test gồm 2 dòng, dòng thứ nhất gồm 1 số nguyên dương n (n<=100), dòng thứ 2 là n số nguyên
// Dữ liệu ra: mỗi test hiện ra độ dài của dãy và tổng các giá trị phần tử dãy đó
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

    int arr[100];
    for (int i = 0; i < n; i++) {
      inputFile >> arr[i];
    }

    int maxLength = 1;
    long long maxSum = arr[0];

    int currentLength = 1;
    long long currentSum = arr[0];

    for (int i = 1; i < n; i++) {
      if (arr[i] > arr[i - 1]) {
        currentLength++;
        currentSum += arr[i];
      } else {
        if (currentLength > maxLength || (currentLength == maxLength && currentSum > maxSum)) {
          maxLength = currentLength;
          maxSum = currentSum;
        }
        currentLength = 1;
        currentSum = arr[i];
      }
    }

    if (currentLength > maxLength || (currentLength == maxLength && currentSum > maxSum)) {
      maxLength = currentLength;
      maxSum = currentSum;
    }

    cout << maxLength << " " << maxSum << endl;
  }

  inputFile.close();
  return 0;
}