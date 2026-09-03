//Viết chương trình nhập vào dãy N số nguyên (0<N<100), 
//tìm số bé nhất và in số lần xuất hiện của số đó trong dãy. 
//Bài tập có NTEST.  Format của input, ouput như sau:
#include <iostream>
#include <fstream>
using namespace std;

void findMinAndCount(int arr[], int N) {
  int minVal = arr[0];
  int count = 1;
  for(int i = 1; i < N; i++) {
    if(arr[i] < minVal) {
      minVal = arr[i];
      count = 1;
    } else if(arr[i] == minVal) {
      count++;
    }
  }
  cout << minVal << " " << count << endl;
}

int main() {
  ifstream inputFile("input.txt");
  if(!inputFile.is_open()) {
    cout << "Khong the mo file." << endl;
    return 1;
  }

  int ntest;
  inputFile >> ntest;

  for(int i = 0; i < ntest; i++) {
    int N;
    inputFile >> N;

    int arr[100];
    for(int j = 0; j < N; j++) {
      inputFile >> arr[j];
    }
    findMinAndCount(arr, N);
  }

  return 0;
}