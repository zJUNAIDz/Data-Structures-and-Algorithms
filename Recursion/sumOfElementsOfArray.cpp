#include <iostream>
using namespace std;
int sum(int arr[], int n, int ans = 0)
{
  // Base Case
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  // Processing
  // Recursive Relation

  ans = arr[0] + sum(arr + 1, n - 1, ans);

  return ans;
}
int main()
{
  int arr[] = {3, 2, 5, 6, 1};
  cout << sum(arr, 5);
  return 0;
}