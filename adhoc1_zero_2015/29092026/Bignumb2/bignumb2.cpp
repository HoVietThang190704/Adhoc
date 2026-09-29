// Tính hiệu của 2 số nguyên dương, độ lớn của mỗi số có thể lên tới 100 chữ số
// Dữ liệu vào “Bignumb2.inp”
// Số đầu tiên là một số nguyên dương NTEST là số lượng test được ghi trên một dòng. Mỗi bộ test gồm 2 dòng mỗi dòng ghi một số cần tính hiệu, số ghi trước là số bị trừ
// Dữ liệu ra “Bignumb2.out”
// Hiện ra NTEST số, mỗi số trên một dòng là hiệu của 2 số đã cho tương ứng.
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

string subtractBigNumbers(string num1, string num2)
{
  bool isNegative = false;
  if (num1.length() < num2.length() || (num1.length() == num2.length() && num1 < num2))
  {
    swap(num1, num2);
    isNegative = true;
  }

  int len1 = num1.length();
  int len2 = num2.length();

  string result = "";
  int carry = 0;

  while (len1 > 0 || len2 > 0 || carry)
  {
    int digit1 = (len1 > 0) ? num1[--len1] - '0' : 0;
    int digit2 = (len2 > 0) ? num2[--len2] - '0' : 0;

    int diff = digit1 - digit2 - carry;
    if (diff < 0)
    {
      diff += 10;
      carry = 1;
    }
    else
    {
      carry = 0;
    }
    result += diff + '0';
  }
  reverse(result.begin(), result.end());

  int pos = 0;
  while (pos < result.length() - 1 && result[pos] == '0')
  {
    pos++;
  }
  result = result.substr(pos);

  if (isNegative && result != "0")
  {
    result = "-" + result;
  }
  return result;
}

int main()
{
  ifstream inputFile("input.txt");
  int NTEST;
  inputFile >> NTEST;
  for (int i = 0; i < NTEST; ++i)
  {
    string num1, num2;
    inputFile >> num1 >> num2;
    string result = subtractBigNumbers(num1, num2);
    cout << result << endl;
  }
  inputFile.close();
  return 0;
}