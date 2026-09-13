// Cho 1 ma trận các số nguyên kích thước m hàng và n cột, 
// hãy xác định hình chữ nhật có kích thước hai chiều là h và k có tổng các phần tử là lớn nhất. 
// Bài tập có Ntest
// Dữ liệu vào: Từ file “Trunghoc16.inp” có format như sau:
//  + Dòng đầu tiên gồm 1 số nguyên dương NTEST (NTEST <= 100) là số lượng test của bài
//  + Mỗi test là một ma trận, bắt đầu là một dòng chứa số m và n là kích cỡ ma trận, 
//2 số nguyên dương h và k (0 < h,k <= 100) tiếp theo là m x n số nguyên. (0 < m,n <= 100)
// Dữ liệu ra: mỗi test hiện ra một số là số tổng lớn nhất có thể của hình chữ nhật, 
//nếu không có hình chữ nhật nào hiện ra 1 số 0
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  int ntest;
  inputFile >> ntest;
  for (int t = 0; t < ntest; t++) {
    int n, m, h, k;
    inputFile >> n >> m >> h >> k;
    int **matrix = new int*[m];
    for (int i = 0; i < m; i++) {
      matrix[i] = new int[n];
    }
    
    long long **prefixSum = new long long*[m + 1];
    for (int i = 0; i <= m; i++) {
      prefixSum[i] = new long long[n + 1]();
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        inputFile >> matrix[i][j];
      }
    }

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        prefixSum[i][j] = matrix[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
      }
    }
    
    bool found = false;
    long long maxSum = LLONG_MIN;

    if (h <= m && k <= n) {
      found = true;
      for (int i = h; i <= m; i++) {
        for (int j = k; j <= n; j++) {
          long long currentSum = prefixSum[i][j] - prefixSum[i - h][j] - prefixSum[i][j - k] + prefixSum[i - h][j - k];
          if (currentSum > maxSum) maxSum = currentSum;
        }
      }
    }

    if (h != k && k <= m && h <= n) {
      found = true;
      for (int i = k; i <= m; i++) {
        for (int j = h; j <= n; j++) {
          long long currentSum = prefixSum[i][j] - prefixSum[i - k][j] - prefixSum[i][j - h] + prefixSum[i - k][j - h];
            if (currentSum > maxSum) maxSum = currentSum;
        }
      }
    }

    if (!found) cout << 0 << "\n";
    else cout << maxSum << "\n";
  }

  inputFile.close();
  return 0;
}
