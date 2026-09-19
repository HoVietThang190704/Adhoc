// Cho một 1 bàn bida băng (không có lỗ) hình chữ nhật kích thước m, n,
// hãy tính toán xem một viên bi khi di chuyển một quãng đường nhất định sẽ chạm mấy lần vào băng (viền của bàn)
// 	Tọa độ viên bi lúc đầu là k, h được cho trước và viên bi luôn được bắn theo góc 45 độ (theo hướng trên phải của bàn)
// Mô tả đường đi của một viên bi xuất phát từ vị trí (5,2)
// di chuyển trong một bàn bida kích thước 17, 4 với một quãng đường độ dài là 17 như sau:
// (“O” là vị trí xuất phát và đường đi của viên bi được mô tả bằng ký tự “.”). Số lần viên bi chạm vào băng là 5.

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream inputFile("input.txt");
  int ntest;
  inputFile >> ntest;

  for (int test = 0; test < ntest; test++)
  {
    int m, n, k, h, d;
    inputFile >> m >> n >> k >> h >> d;

    int x = k, y = h;
    int dx = 1, dy = 1;
    int hit_count = 0;

    while (d > 0) {
      x += dx;
      y += dy;
      d--;
      bool hit = false;
      if (x == 0 || x == m) {
        dx = -dx;
        hit = true;
      }
      if (y == 0 || y == n) {
        dy = -dy;
        hit = true;
      }
      if (hit) {
        hit_count++;
      }
    }
    cout << hit_count << endl;
  }

  inputFile.close();
  return 0;
}