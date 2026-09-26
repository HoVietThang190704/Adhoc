#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream inputFile("input.txt");

  int ntest;
  inputFile >> ntest;

  for (int t = 0; t < ntest; t++)
  {
    int n;
    inputFile >> n;

    long long *a = new long long[n];
    long long totalSum = 0;

    for (int i = 0; i < n; i++)
    {
      inputFile >> a[i];
      totalSum += a[i];
    }

    long long sumtarget = totalSum;
    long long prefix = 0;

    for (int i = 0; i < n; i++)
    {
      prefix += a[i];
      long long currentTarget = prefix;

      if (currentTarget != 0 && totalSum % currentTarget == 0)
      {
        long long tempSum = 0;
        bool valid = true;

        for (int j = 0; j < n; j++)
        {
          tempSum += a[j];

          if (tempSum > currentTarget)
          {
            valid = false;
            break;
          }

          if (tempSum == currentTarget)
          {
            tempSum = 0;
          }
        }

        if (valid && tempSum == 0)
        {
          sumtarget = currentTarget;
          break;
        }
      }
    }

    long long tempSum = 0;

    for (int i = 0; i < n; i++)
    {
      tempSum += a[i];
      cout << a[i];

      if (tempSum == sumtarget && i != n - 1)
      {
        cout << " / ";
        tempSum = 0;
      }
      else if (i != n - 1)
      {
        cout << " ";
      }
    }

    cout << endl;

  }

  inputFile.close();
  return 0;
}