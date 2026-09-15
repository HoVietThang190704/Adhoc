// Tại một mỏ kim cương ở Nam Phi, người ta đã tiến hành chụp cắt lớp các khu đất, 
// kết quả scan được máy hiển thị dưới dạng 1 ma trận nhị phân kích thước m x n, 
// hãy viết chương trình nhận dạng ảnh để dự đoán xem khu đất đó có viên kim cương to nhất có kích thước có thể là bao nhiêu. 
// Một viên kim cương có đặc điểm nhận dạng sau: 
//  - Hình thoi gồm toàn những số 0
//  - Kích thước các chiều là một số lẻ lớn hơn 1.
// Ví dụ một viên kim cương kích thước 3 có dạng sau:
//  0
// 000
//  0
// Dữ liệu vào: Từ file “Trunghoc18.inp” có format như sau:
//  + Dòng đầu tiên gồm 1 số nguyên dương NTEST (NTEST <= 100) là số lượng test của bài
//  + Mỗi test là một ma trận, bắt đầu là một dòng chứa số m, n,là kích cỡ ma trận, 
//tiếp theo là m x n số nguyên. (0 < m,n <= 100).
// Dữ liệu ra: mỗi test hiện ra kích thước viên kim cương lớn nhất. Nếu không có viên nào in ra một số 0
#include <iostream>
#include <fstream>
using namespace std;

bool checkRing(int **matrix, int r, int c, int k) {
  for (int d = 0; d < k; d++) {
    int span = k - d;
    if (matrix[r - d][c-span] != 0) return false;
    if (matrix[r - d][c+span] != 0) return false;
    if (matrix[r + d][c-span] != 0) return false;
    if (matrix[r + d][c+span] != 0) return false;
  }
  return true;
}

int main() {
  ifstream inputFile("input.txt");
  int ntest;
  inputFile >> ntest;

  for (int t = 0; t < ntest; t++) {
    int m, n;
    inputFile >> m >> n;
    int **matrix = new int*[m];
    for (int i = 0; i < m; i++) {
      matrix[i] = new int[n];
      for (int j = 0; j < n; j++) {
        inputFile >> matrix[i][j];
      }
    }

    int maxDiamondSize = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] != 0) continue;
        cout << "Checking center at (" << i << ", " << j << ")" << endl;

        int max_k = min(min(i, m - 1 - i), min(j, n - 1 - j));
        cout << "Max k for this center: " << max_k << endl;
        
        if (2 * max_k + 1 <= maxDiamondSize) continue;
        cout << "Current max diamond size: " << maxDiamondSize << endl;
        cout << "Checking rings around this center." << endl;

        int currentSize = 0;
        for (int k = 1; k <= max_k; k++) {
          if (checkRing(matrix, i, j, k)) {
            currentSize = k;
          } else {
            break;
          }
        } 

        if (currentSize > 0) {
          int size = 2 * currentSize + 1;
          if (size > maxDiamondSize) {
            maxDiamondSize = size;
          }
        }
      }
    }
    cout << maxDiamondSize << endl;
  }
  inputFile.close();
  return 0;
}

