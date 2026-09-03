//Viết chương trình nhập vào N số nguyên (0<N<100), 
//tính tổng các phần tử chẵn, các phần tử lẻ, các phần tử chia hết cho K 
//và in kết quả ra màn hình lần lượt 3 giá trị cần tìm. Bài tập có NTEST.
//Format của input, ouput như sau 
//(dòng đầu mỗi test gồm 2 số N và K, dòng thứ 2 là N số của dãy cần tính)
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  if (!inputFile) {
    cerr << "Khong the mo file input.txt" << endl;
    return 1;
  }

  int ntest;
  inputFile >> ntest;
  for (int t = 0; t < ntest; ++t) {
    int N, K;
    inputFile >> N >> K;
    int sumEven = 0, sumOdd = 0, sumDivK = 0;
    for (int i = 0; i < N; ++i) {
      int num;
      inputFile >> num;
      if (num % 2 == 0) {
        sumEven += num;
      } else {
        sumOdd += num;
      }
      if (num % K == 0) {
        sumDivK += num;
      }
    }
    cout << sumEven << " " << sumOdd << " " << sumDivK << endl;
  }
}