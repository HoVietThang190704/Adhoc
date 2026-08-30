//Viết chương trình nhập vào N số nguyên (0<N<100), đếm xem có bao nhiêu số âm, bao nhiêu số dương và bao nhiêu số không.
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  if (!inputFile.is_open()) {
    cerr << "Khong the mo file input." << endl;
    return 1;
  }

  int N;
  inputFile >> N;
  if (N <= 0 || N >= 100) {
    cerr << "Gia tri N khong hop le. Vui long nhap mot so nguyen duong nho hon 100." << endl;
    return 1;
  }

  int negativeCount = 0;
  int positiveCount = 0;
  int zeroCount = 0;

  for (int i = 0; i < N; i++) {
    int number;
    inputFile >> number;
    if (number < 0) negativeCount++;
    else if (number > 0) positiveCount++;
    else zeroCount++;
  }

  cout << "Co " << negativeCount << " so am" << endl;
  cout << "Co " << positiveCount << " so duong" << endl;
  cout << "Co " << zeroCount << " so khong" << endl;
}