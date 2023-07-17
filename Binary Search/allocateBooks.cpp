#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> &arr, int n, int m, int mid)
{
  int studentRequired = 1;
  int currSum = 0;
  for (int i = 0; i < n; i++)
  {
    if (currSum + arr[i] > mid)
    {

      studentRequired++;
      currSum = arr[i];
    }
    else
      currSum += arr[i];

    if (arr[i] > mid)
      return false;
    if (studentRequired > m)
      return false;
  }
  return true;
}

int findPages(vector<int> &arr, int n, int m)
{
  if (n < m)
    return -1;
  int sum = 0;
  for (auto &i : arr)
  {
    sum += i;
  }
  int start = 0;
  int end = sum;
  int mid;
  int ans = 0;
  while (start <= end)
  {
    mid = start + (end - start) / 2;
    if (isPossible(arr, n, m, mid))
    {
      ans = mid;
      end = mid - 1;
    }
    else
      start = mid + 1;
  }
  return ans;
}

int main()
{
  vector<int> arr = {8, 15, 3};
  cout << findPages(arr, arr.size(), 2);
  return 0;
}