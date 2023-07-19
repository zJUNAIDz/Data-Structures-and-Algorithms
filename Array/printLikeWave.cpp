#include <iostream>
using namespace std;
void printWave(int arr[3][3], int row, int col)
{
  // looping variables bana lo
  int i = 0;
  int columnNumber = 1;
  // loop chalke column-wise print kardo hehe
  while (i < col)
  {
    if (columnNumber % 2 == 0)
    {
      int j = row - 1;
      while (j >= 0)
        cout << arr[j--][i] << ' ';
      columnNumber++;
    }
    else
    {
      int j = 0;
      while (j < row)
        cout << arr[j++][i] << ' ';
      columnNumber++;
    }
    i++;
  }
}
int main()
{
  int arr[3][3] = {{1, 2, 3},
                   {4, 5, 6},
                   {7, 8, 9}};
  printWave(arr, 3, 3);
  return 0;
}