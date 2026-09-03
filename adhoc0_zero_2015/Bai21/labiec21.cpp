//Viết chương trình nhập vào dãy N số nguyên (0<N<100), 
//tìm số bé nhất và in số lần xuất hiện của số đó trong dãy. 
//Bài tập có NTEST.  Format của input, ouput như sau:
#include <iostream>
#include <fstream>
using namespace std;

int findMin(int arr[], int N) {
  int min = arr[0];
    for(int i = 1; i < N; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

int countOccurrences(int arr[], int N, int target) {
  int count = 0;
  for(int i = 0; i < N; i++) {
    if(arr[i] == target) {
      count++;
    }
  }
  return count;
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

    int minValue = findMin(arr, N);
    int occurrences = countOccurrences(arr, N, minValue);

    cout << minValue << " " << occurrences << endl;
  }

  return 0;
}