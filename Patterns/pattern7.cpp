#include <iostream>
using namespace std;

int main()
{
  // int row, col;
  // cout << "enter number of rows : ";
  // cin >> row;
  // cout << "enter number of columns : ";
  // cin >> col;
  // char arr[]={'A','B','C'};
  int row=3,col=3;
  // int count = 1;
  // for (int i = 0; i <  row; i++)
  // {
  //   for (int j = 0; j < col; j++)
  //   {
  //     cout << arr[i] << ' ';
  //   }
  //   cout << endl;
  // }


  //or 
  char ch = 'A';
  for (int i = 0; i <  row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      cout << ch << ' ';
    }
    ch++;
    cout << endl;
  }

  return 0;
}

