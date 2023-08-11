#include <iostream>
#include <vector>
using namespace std;

void printIntArray(int *arr)
{
  int len = sizeof(arr) / sizeof(arr[0]);
  cout << "[";
  for (int i = 0; i <= len - 1; i++)
  {
    cout << arr[i];
    if (i != len - 1)
      cout << ", ";
  }
  cout << "]";
}
void printIntVector(vector<int> &arr)
{
  int len = sizeof(arr) / sizeof(arr[0]);
  cout << "[";
  for (int i = 0; i <= len - 1; i++)
  {
    cout << arr[i];
    if (i != len - 1)
      cout << ", ";
  }
  cout << "]";
}