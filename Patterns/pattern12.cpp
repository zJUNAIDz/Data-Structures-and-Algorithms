#include <iostream>
using namespace std;
int main()
{
  int row = 1;
  int n = 5;
  while (row <= n)
  {
    // spaces print karo
    int spaces = 0;
    while (spaces <= n - row)
    {
      cout << ' ';
      spaces++;
    }
    // stars print karo
    int col = 1;
    while (col <= row)
    {
      cout << col;
      col++;
    }

    // fir k stars print karo
    // int ncol = row -1;
    // while (ncol <= row)
    // {
    //   int cnt = ncol-1;
    //   cout << ncol-row+1;
    //   ncol++;
    //   cnt--;  
    // }

    int start = row -1;
    while(start){
      cout << start;
      start--;
    }
    cout << endl;
    row++;
  }

  return 0;
}