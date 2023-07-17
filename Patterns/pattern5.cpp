#include <iostream>
using namespace std;

int main()
{
  // int row, col;
  // cout << "enter number of rows : ";
  // cin >> row;
  // cout << "enter number of columns : ";
  // cin >> col;
  int count = 1;
  for (int i = 1; i <= 4; i++)
  {
    for (int j = 0; j < i; j++)
    {
      cout << i+j << ' ';
    }
    cout << endl;
  }
  return 0;
}