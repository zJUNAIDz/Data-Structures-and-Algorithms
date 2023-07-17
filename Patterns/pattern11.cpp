#include <iostream>
using namespace std;

int main()
{
  int row = 1;
  int n = 5;
  while (row <= n)
  {
    // space print karo
    int spaces = 0;
    while (spaces < row - 1)
    {
      cout << ' ';
      spaces++;
    }

    // stars print karo
    int col = 1;
    while (col <= n - row + 1)
    {
      cout << row;
      col++;
    }
    cout << endl;
    row++;
  }
  return 0;
}
