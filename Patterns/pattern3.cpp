#include <iostream>
using namespace std;
int main()
{
  // int row, col;
  // cout << "enter number of rows : ";
  // cin >> row;
  // cout << "enter number of columns : ";
  // cin >> col;
  for (int i = 1; i < 4; i++)
  {
    for (int j = 1; j <= 4; j++)
    {
      cout << 4 - j + 1; // Reverse order
    }
    cout << endl;
  }
  return 0;
}

