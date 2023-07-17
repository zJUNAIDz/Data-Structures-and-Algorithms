#include <iostream>
using namespace std;

int main()
{
  int row=3,col=3;
  char ch = 'A';
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      cout << ch << ' ';
      ch='A'+i+j-2;
    }
    cout << endl;
  }

  return 0;
}