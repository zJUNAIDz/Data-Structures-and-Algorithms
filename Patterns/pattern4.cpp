#include <iostream>
using namespace std;

int main()
{
  // int row, col;
  // cout << "enter number of rows : ";
  // cin >> row;
  // cout << "enter number of columns : ";
  // cin >> col;
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      cout << i << ' ';
    }
    cout << endl;
  }
  return 0;
}