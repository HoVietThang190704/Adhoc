// Một dãy số nguyên tố (1,2,3…) trong đó mỗi số chỉ chia hết cho 1 và chính nó.
// Hãy viết một chương trình cắt một số số nguyên tố ra khỏi dãy số nguyên tố từ 1 đến N
// (bao gồm cả 1 và N nếu N là số nguyên tố).
// Đọc vào số N; xác định danh sách các số nguyên tố giữa 1 và N,
// in ra C*2 số nguyên tố ở giữa (trung tâm) dãy
// nếu số lượng số nguyên tố của dãy là số chẵn hoặc
// in ra C*2-1 số nguyên tố ở giữa dãy nếu số lượng số nguyên tố của dãy là số lẻ
// Input “406.inp”
// File input gồm 1 số test, mỗi test ghi trên một dòng bao gồm 2 số. Số đầu tiên (1<=N<=1000), số thứ 2 (1<=C<=N)
// Output “406.out”
// Với mỗi test, in ra “N C: ”, tiếp đó là dãy các số nguyên tố ở giữa, các số cách nhau một dấu trắng.
// Nếu dãy các số nguyên tố ở giữa dài hơn dãy nguyên tố gốc thì in ra dãy nguyên tố gốc. Giữa 2 test là 1 dòng trắng.
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
  if (n <= 1)
    return true;
  if (n < 2)
    return false;
  for (int i = 2; i <= sqrt(n); i++)
  {
    if (n % i == 0)
      return false;
  }
  return true;
}

int main()
{
  ifstream inputFile("input.txt");
  int n, c;
  bool isFirstOutput = true;

  while (inputFile >> n >> c)
  {
    int primes[1000];
    int count = 0;

    for (int j = 1; j <= n; j++)
    {
      if (isPrime(j))
      {
        primes[count++] = j;
      }
    }

    int countToTake;
    if (count % 2 == 0)
    {
      countToTake = c * 2;
    }
    else
    {
      countToTake = c * 2 - 1;
    }

    if (countToTake > count)
    {
      countToTake = count;
    }

    int start = (count - countToTake) / 2;

    if (!isFirstOutput)
    {
      cout << "\n";
    }

    cout << n << " " << c << ":";

    for (int k = start; k < start + countToTake; k++)
    {
      cout << " " << primes[k];
    }

    isFirstOutput = false;
  }
}