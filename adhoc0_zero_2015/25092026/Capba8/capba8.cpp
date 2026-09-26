// Có một số phép xử lý với chuỗi sau: 
// append s1 s2 (nối chuỗi s2 vào ngay sau chuỗi s1)
// right x s (cắt lấy x phần tử từ phía bên phải của chuỗi s)
// left x s (cắt lấy x phần tử từ phía bên trái của chuỗi s)
// delete x y s (xóa x phần tử tính từ vị trí thứ y trong chuỗi s)
// proper s (in hoa chữ cái đầu của các từ trong chuỗi)

// Cho vào một số phép, hãy in ra kết quả
// Chú ý:
//  - Không chuỗi nào quá 256 ký tự 
//  - Ký tự trắng trong file input được chuyển thành ký tự “_” khi in ra phải chuyển lại thành ký tự trắng
// Dữ liệu vào: Từ file “Capba8.inp” có format như sau:
//  - Dòng đầu tiên gồm 1 số nguyên dương N (N <= 100) là số lượng phép cần xử lý
//  - N dòng tiếp theo lần lượt là các phép
//  Dữ liệu ra: Ghi kết quả của phép, mỗi kết quả trên một dòng
#include <iostream>
#include <fstream>
using namespace std;

string replace_underscores_with_spaces(string s) {
  for (char &c : s) {
    if (c == '_') {
      c = ' ';
    }
  }
  return s;
}

string append(string s1, string s2) {
  s1 = replace_underscores_with_spaces(s1);
  s2 = replace_underscores_with_spaces(s2);
  return s1 + s2;
}

string right(int x, string s) {
  s = replace_underscores_with_spaces(s);
  if (x > s.length()) {
    return s;
  }
  return s.substr(s.length() - x);
}

string left(int x, string s) {
  s = replace_underscores_with_spaces(s);
  if (x > s.length()) {
    return s;
  }
  return s.substr(0, x);
}

string delete_substring(int x, int y, string s) {
  s = replace_underscores_with_spaces(s);
  if (y - 1 < 0 || y - 1 >= s.length() || x < 0 || y - 1 + x > s.length()) {
    return s;
  }
  return s.erase(y - 1, x);
}

string proper(string s) {
  s = replace_underscores_with_spaces(s);
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '_') {
      s[i] = ' ';
    }
    if (i == 0 || isspace(s[i - 1])) {
      s[i] = toupper(s[i]);
    } else {
      s[i] = tolower(s[i]);
    }
  }
  return s;
}

int main() {
  ifstream inputFile("input.txt");
  int ntest;
  inputFile >> ntest;

  for (int t = 0; t < ntest; t++) {
    string command;
    inputFile >> command;

    for (char &c : command) {
      c = tolower(c);
    }

    if (command == "append") {
      string s1, s2;
      inputFile >> s1 >> s2;
      cout << append(s1, s2) << endl;
    } else if (command == "right") {
      int x;
      string s;
      inputFile >> x >> s;
      cout << right(x, s) << endl;
    } else if (command == "left") {
      int x;
      string s;
      inputFile >> x >> s;
      cout << left(x, s) << endl;
    } else if (command == "delete") {
      int x, y;
      string s;
      inputFile >> x >> y >> s;
      cout << delete_substring(x, y, s) << endl;
    } else if (command == "proper") {
      string s;
      inputFile >> s;
      cout << proper(s) << endl;
    }
  }

  inputFile.close();
  return 0;
}
