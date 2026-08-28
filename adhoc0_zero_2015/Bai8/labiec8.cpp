//Viết chương trình tính tổng nghịch đảo của N số nguyên đầu tiên theo công thức:
//S = 1 + 1/2 + 1/3 + … + 1/N
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
  ifstream fin("labiec8.txt");
  if (!fin) {
    cout << "Không thể mở file labiec8.txt" << endl;
    return 1;
  }

  int n;
  fin >> n;
  fin.close();
  if (n <= 0) {
    cout << "N phải là một số nguyên dương." << endl;
    return 1;
  }

  double sum = 0.0;
  for (int i = 1; i <= n; i++) {
    sum += 1.0 / i;
  }
  cout << fixed << setprecision(6) << sum << endl;
  return 0;
}