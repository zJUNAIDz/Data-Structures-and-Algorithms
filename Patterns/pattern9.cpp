#include <iostream>
using namespace std;

int main()
{
  int n = 4;
  int row = 1;
  while (row <= n)
  {
    // space print karo
    int space = n - row;
    while (space)
    {
      cout << "  ";
      space--;
    }
    // stars print karo
    int col = 1;
    while (col <= row)
    {
      cout << "* ";
      col++;
    }
    row++;
    cout << endl;
  }
}