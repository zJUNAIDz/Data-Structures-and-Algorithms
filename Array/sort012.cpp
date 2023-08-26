#include <iostream>
using namespace std;

void printIntArray(int *arr, int len)
{
  // int len = sizeof(arr) / sizeof(arr[0]);
  cout << "[";
  for (int i = 0; i < len; i++)
  {
    cout << arr[i];
    if (i != len - 1)
      cout << ", ";
  }
  cout << "]";
  cout << endl;
}
void sort012(int *arr, int n)
{
  int low = 0;
  int high = n - 1;
  int mid = 0;
  while (mid <= high)
  {

    if (arr[mid] == 0)
      swap(arr[low++], arr[mid++]);
    else if (arr[mid] == 1)
      mid++;
    else
      swap(arr[mid], arr[high--]);
  }
}
int main()
{
  int arr[] = {1, 2, 0, 0, 2, 0, 0, 1, 2, 0, 1, 0, 2, 2, 0, 1, 0};
  int n = sizeof(arr) / sizeof(arr[0]);
  printIntArray(arr, n);
  sort012(arr, n);
  printIntArray(arr, n);
  return 0;
}