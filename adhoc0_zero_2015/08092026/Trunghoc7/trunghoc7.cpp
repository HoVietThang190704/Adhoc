// Cho một ma trận nhị phân (các phần tử trong ma trận chỉ có giá trị 0 hoặc 1)
// Tìm số lượng các hình vuông thuộc ma trận trên sao cho các phần tử trong hình vuông đều có giá trị khác 0
// Dữ liệu đầu vào: Từ file văn bản “SQUARE.INP” có định dạng như sau:
//  + Dòng đầu tiên ghi một số NTEST là số lượng ma trận (0 < NTEST <=1000)
//  + Tiếp theo là NTEST bộ dữ liệu trong đó:
// 	+ Dòng đầu gồm 3 số: số hàng, số cột và kích cỡ của hình vuông cần tìm (giá trị không quá 100)
//             + Các giá trị của ma trận tương ứng
// Đầu ra:
// Gồm NTEST dòng, mỗi dòng hiện số lượng hình vuông thỏa mãn yêu cầu ứng với từng ma trận và kích cỡ hình vuông đã cho.
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream inputFile("input.txt");
  if (!inputFile.is_open())
  {
    cout << "Khong the mo file input.txt" << endl;
    return 1;
  }

  int NTEST;
  inputFile >> NTEST;
  if (NTEST <= 0 || NTEST > 1000)
  {
    cout << "Gia tri NTEST khong hop le" << endl;
    return 1;
  }

  for (int test = 0; test < NTEST; ++test)
  {
    int rows, cols, squareSize;
    inputFile >> rows >> cols >> squareSize;
    if (rows <= 0 || rows > 100 || cols <= 0 || cols > 100 || squareSize <= 0 || squareSize > 100)
    {
      cout << "Gia tri rows, cols hoac squareSize khong hop le" << endl;
      return 1;
    }

    int **matrix = new int *[rows];
    for (int i = 0; i < rows; ++i)
    {
      matrix[i] = new int[cols];
      for (int j = 0; j < cols; ++j)
      {
        inputFile >> matrix[i][j];
        if (matrix[i][j] != 0 && matrix[i][j] != 1)
        {
          cout << "Gia tri ma tran khong hop le" << endl;
          return 1;
        }
      }
    }

    int count = 0;
    for (int i = 0; i <= rows - squareSize; ++i)
    {
      for (int j = 0; j <= cols - squareSize; ++j)
      {
        bool isSquareValid = true;
        for (int x = 0; x < squareSize && isSquareValid; ++x)
        {
          for (int y = 0; y < squareSize; ++y)
          {
            if (matrix[i + x][j + y] == 0)
            {
              isSquareValid = false;
              break;
            }
          }
        }
        if (isSquareValid)
        {
          count++;
        }
      }
    }
    cout << count << endl;
  }

  inputFile.close();
  return 0;
}
