#include <iostream>
using namespace std;
bool linear_search(int arr[], int size, int key)
{
  // Base Case
  if (size == 0)
    return 0;
  if (arr[0] == key)
    return 1;
  // Processing
  return linear_search(arr + 1, size - 1, key);
}
int main()
{
  int arr[] = {1, 2, 3, 4, 5, 65, 3, 2, 22, 45, 43, 45, 92, 67, 78, 90, 66, 55, 9, 44, 48, 3, 33};
  int size = 23;
  int key = 9;
  cout << linear_search(arr, size, key);
  return 0;
}