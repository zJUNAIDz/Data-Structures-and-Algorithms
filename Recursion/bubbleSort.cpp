#include <iostream>
#include <vector>
using namespace std;
void sort_arr(vector<int> &arr, int n)
{
  // Base Case
  if (n == 0 || n == 1)
    return;

  // processing
  for (int i = 0; i < n - 1; i++)
  {
    if (arr[i] > arr[i + 1])
    {
      swap(arr[i], arr[i + 1]);
    }
  }
  // Recursive Call
  sort_arr(arr, n - 1);
  /*
   * **Recursion feels so Magical haha
   */
}
int main()
{
  vector<int> arr = {2, 9, 5, 4, 3, 299, 87, 66, 4, 66, 6, 5, 7, 8, 44, 345, 9, 33};
  sort_arr(arr, arr.size());
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << ' ';
  }
  return 0;
}