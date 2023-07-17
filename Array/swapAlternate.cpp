#include <iostream>
using namespace std;

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int len = sizeof(arr) / sizeof(int);
  for (int i = 0; i <= sizeof(arr) / sizeof(int); i += 2)
  {
    if (i + 1 < len)
      swap(arr[i], arr[i + 1]);
  }
  for (int i = 0; i <= sizeof(arr) / sizeof(int); i++)
  {
    cout << arr[i] << ' ';
  }
  return 0;
}