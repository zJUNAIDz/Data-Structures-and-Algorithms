#include <iostream>
using namespace std;

int main()
{
  // int row, col;
  // cout << "enter number of rows : ";
  // cin >> row;
  // cout << "enter number of columns : ";
  // cin >> col;
  int row=25,col=4;
  int count = 1;
  for (int i = 0; i <  row; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      cout << i-j+1 << ' ';
    }
    cout << endl;
  }
  return 0;
}