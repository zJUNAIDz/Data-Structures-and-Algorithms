// Taught by bhaiyya
#include <iostream>
using namespace std;

int binary_search(int *arr, int start, int end, int key)
{
  if (start > end)
  {
    return -1;
  }
  int mid = start + (end - start) / 2;
  if (arr[mid] == key)
    return mid;
  if (arr[mid] < key)
    return binary_search(arr, mid + 1, end, key);
  else
    return binary_search(arr, start, mid - 1, key);
} 
int main()
{
  int arr[] = {2, 3, 5, 6, 7, 8, 12, 23, 26, 35, 47, 58, 69, 70}; // sorted
  int size = sizeof(arr) / sizeof(arr[0]);
  int start = 0;
  int end = size - 1;
  int key = 35;
  cout << binary_search(arr, start, end, key);
  return 0;
}