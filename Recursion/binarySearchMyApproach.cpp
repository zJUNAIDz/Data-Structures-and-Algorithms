#include <iostream>
using namespace std;
bool binary_search(int *arr, int size, int key)
{
  // doing Binary search the Recursive way
  // Binary search variables
  int start = 0;
  int end = size - 1;
  int mid = start + (end - start) / 2;
  // base Case
  if (size == 0)
  {
    return 0;
  }

  // If found
  else if (arr[mid] == key)
    return 1;
  // if arr[mid]< key
  else if (arr[mid] < key)
  {
    start = binary_search(arr + mid + 1, size - mid, key);
  }
  else
  {
    end = binary_search(arr, size - mid - 1, key);
  }
  // mid = start + (end - start) / 2;
}
int main()
{
  int arr[] = {2, 3, 5, 6, 7, 8, 12, 23, 26, 35, 47, 58, 69, 70}; // sorted
  int size = sizeof(arr) / sizeof(arr[0]);
  int key = 700 ;
  cout << binary_search(arr, size, key);

  return 0;
}