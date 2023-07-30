#include <iostream>
#include <vector>
using namespace std;
void sort_arr(vector<int> &arr, int n, int i = 0)
{
  // Base Case
  if (i == n)
    return;
  // Processing
  // for just 1 case or round
  for (int j = i + 1; j < n; j++)
    if (arr[i] > arr[j])
      swap(arr[i], arr[j]);
  // Recursive Call
  sort_arr(arr, n, i + 1);
}
int main()
{
  vector<int> arr = {2, 9, 5, 4, 3, 299, 87, 66, 4, 66, 6, 5, 7, 8, 44, 345, 9};
  sort_arr(arr, arr.size());
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << ' ';
  }

  return 0;
}