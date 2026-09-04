//Viết chương trình nhập vào dãy N số nguyên (0<N<100), 
//xác định xem dãy có phải cấp số cộng hay không, 
//nếu không in ra “khong phai day cap so cong”, 
//nếu đúng in ra 1 số là cấp số cộng đó. 
//Bài có NTEST (dòng đầu mỗi test gồm 1 số N, dòng thứ 2 là N số của dãy)
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
  if (!(inputFile >> ntest)) {
    cout << "Khong doc duoc so luong test" << endl;
    return 0;
  }

  for (int i = 0; i < ntest; i++) {
    int N;
    if (!(inputFile >> N) || N <= 0 || N >= 100) {
      cout << "Khong doc duoc so luong phan tu hoac gia tri khong hop le" << endl;
      continue;
    }

    int arr[100];
    for (int j = 0; j < N; j++) {
      if (!(inputFile >> arr[j])) {
        cout << "Khong doc duoc phan tu thu " << j + 1 << endl;
        continue;
      }
    }

    if (N == 1) {
      cout << 0 << endl;
      continue;
    }

    int commonDifference = arr[1] - arr[0];
    bool isArithmetic = true;

    for (int j = 1; j < N - 1; j++) {
      if (arr[j + 1] - arr[j] != commonDifference) {
        isArithmetic = false;
        break;
      }
    }

    if (isArithmetic) {
      cout << commonDifference << endl;
    } else {
      cout << "khong phai day cap so cong" << endl;
    }
  }

  inputFile.close();
  return 0;
}