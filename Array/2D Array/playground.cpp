#include <iostream>
using namespace std;
int main()
{
  char arr[6] = "abc\0e";
  // cout << arr;
  
  int a[3] = {1, 2, 3};
  int *p = a + 2;
  cout << *p ;
  return 0;
}