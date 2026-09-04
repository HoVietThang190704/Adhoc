//Viết chương trình nhập vào dãy N số nguyên (1<N<100), 
//xác định xem dãy đan dấu hay không (âm, dương xen kẽ nhau liên tiếp), 
//nếu không in ra “0” nếu đúng in ra “1”. 
//Bài có NTEST (dòng đầu mỗi test gồm 1 số N, dòng thứ 2 là N số của dãy)
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  if (!inputFile) {
    cerr << "Khong the mo file." << endl;
    return 1;
  }

  int ntest;
  inputFile >> ntest;
  for (int i = 0; i < ntest; ++i) {
    int N;
    inputFile >> N;
    if (N <= 1 || N >= 100) {
      cerr << "Gia tri N khong hop le." << endl;
      return 1;
    }

    int* arr = new int[N];
    for (int j = 0; j < N; ++j) {
      inputFile >> arr[j];
    }

    bool isAlternating = true;
    for (int j = 1; j < N; ++j) {
      if ((arr[j] >= 0 && arr[j - 1] >= 0) || (arr[j] < 0 && arr[j - 1] < 0)) {
        isAlternating = false;
        break;
      }
    }

    if (isAlternating) {
      cout << "1" << endl;
    } else {
      cout << "0" << endl;
    }

    delete[] arr;
  }

  inputFile.close();
  return 0;
}