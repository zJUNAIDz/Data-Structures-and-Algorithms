#include <iostream>
using namespace std;
int main()
{
  int arr[] = {1, 8, 3, 4, 5};
  int *p = &arr[0];
  cout << *(p+1);
  return 0;
}