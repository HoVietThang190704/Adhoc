// Tính tổng của 2 số nguyên dương, độ lớn của mỗi số có thể lên tới 100 chữ số
// Dữ liệu vào “Bignumb1.inp”
// Số đầu tiên là một số nguyên dương NTEST là số lượng test được ghi trên một dòng.
// Mỗi bộ test gồm 2 dòng mỗi dòng ghi một số cần tính tổng
// Dữ liệu ra “Bignumb1.out”
// Hiện ra NTEST số, mỗi số trên một dòng là tổng của 2 số đã cho tương ứng.
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

string addBigNumbers(string num1, string num2)
{
  string result;
  int carry = 0;
  int len1 = num1.size();
  int len2 = num2.size();

  while (len1 > 0 || len2 > 0 || carry > 0)
  {
    int digit1 = (len1 > 0) ? num1[len1 - 1] - '0' : 0;
    int digit2 = (len2 > 0) ? num2[len2 - 1] - '0' : 0;

    int sum = digit1 + digit2 + carry;
    carry = sum / 10;
    result.push_back((sum % 10) + '0');

    len1--;
    len2--;
  }

  reverse(result.begin(), result.end());
  return result;
}

int main()
{
  ifstream inputFile("input.txt");
  int NTEST;
  inputFile >> NTEST;

  for (int t = 0; t < NTEST; ++t)
  {
    string num1, num2;
    inputFile >> num1 >> num2;

    string sum = addBigNumbers(num1, num2);
    cout << sum << endl;
  }

  inputFile.close();
  return 0;
}