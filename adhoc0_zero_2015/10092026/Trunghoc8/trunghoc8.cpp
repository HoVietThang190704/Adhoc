// Xem xét thuật toán sau đây:   
// 1.                  Nhập vào n
// 2.                  In ra n
// 3.                  Nếu n = 1 thì KẾT THÚC
// 4.                  Nếu n lẻ thì  n= 3n+1
// 5.                  Ngược lại (n chẵn) thì n= n/2
// 6.                  Quay lại bước 2
 
// Với thuật toán trên nếu cho đầu vào 22, 
//trình tự sau đây của các số sẽ được in 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1 
// Cho một đầu vào là n, có thể để xác định số lượng các con số được in (bao gồm số 1). 
//Đối với mỗi số n như vậy thì số lượng các con số được sinh ra liên tiếp từ đó được gọi là chu kỳ dài của n. 
//Trong ví dụ trên, chu kỳ dài của 22 là 16. 
// Đối với bất kỳ hai số i và j bạn phải xác định chu kỳ dài nhất các số giữa i và j. 
// Đầu vào: 
// Dữ liệu được ghi trong file văn bản “3N1.INP” có định dạng như sau:
// Dòng đầu tiên ghi một sô n là số lượng cấp số nguyên i và j (0<n<=1000)
// Mỗi dòng trong n dòng tiếp theo ghi các cặp số nguyên i và j (0<i <= j <=10.000) 
// Bạn cần xử lý tất cả các cặp số nguyên 
//và chỉ ra chu kỳ dài nhất của mỗi cặp trên tất cả các số nguyên giữa và bao gồm cả i và j. 
// Đầu ra: 
// Đối với mỗi cặp số nguyên đầu vào i và j bạn ghi đầu ra i, j, 
//và chu kỳ dài nhất cho các số nguyên giữa và bao gồm cả i và j. 
//Ba con số cần được ngăn cách bởi ít nhất một khoảng trắng, 
//cả ba con số trên một dòng và mỗi dòng này ứng với một dòng của đầu vào đã cho. 
//Các số nguyên i và j phải có mặt ở kết quả in ra và theo đúng như thứ tự như trong đầu vào, 
//tiếp theo đó là chiều dài tối đa chu kỳ (trên cùng một dòng). 
#include <iostream>
#include <fstream>
using namespace std;

int cycle_length(int n) {
  int length = 1;
  while (n != 1) {
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = 3 * n + 1;
    }
    length++;
  }
  return length;
}

int main() {
  ifstream inputFile("input.txt");

  int ntest;
  inputFile >> ntest;
  for (int t = 0; t < ntest; ++t) {
    int i, j;
    inputFile >> i >> j;
    int max_cycle_length = 0;
    for (int num = i; num <= j; ++num) {
      int current_cycle_length = cycle_length(num);
      if (current_cycle_length > max_cycle_length) {
        max_cycle_length = current_cycle_length;
      }
    }
    cout << i << " " << j << " " << max_cycle_length << endl;
  }

  inputFile.close();
  return 0;
}