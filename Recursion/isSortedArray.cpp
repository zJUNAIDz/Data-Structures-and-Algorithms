#include <iostream>
using namespace std;
bool isSortedArray(int arr[], int n)
{
  // bool ans;
  // Base Case
  if (n == 0 || n == 1)
    return true;
  // Processing
  if (arr[0] > arr[1])
    return false;
  else
  {
    bool ans = isSortedArray(arr + 1, n - 1);
    return ans;
  }
}
int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 23, 7, 8};
  int n = 7;
  cout << isSortedArray(arr, n);
  return 0;
}