#include <iostream>
#include <vector>
using namespace std;
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

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
  //--------------------------------------------------------------------
  //*Brute Force (unoptimized)
  //! Will cause TLE in submission
  //*initial pointers for window
  int s = 0;
  int e = k - 1;
  //*vector in which we gonna store max value of window
  vector<int> ans;
  while (e <= nums.size() - 1)
  {
    int maxValue = INT_MIN;
    for (int i = s; i <= e; i++)
      maxValue = max(maxValue, nums[i]);
    ans.push_back(maxValue);
    //*sliding window to left by 1
    s++;
    e++;
  }
  return ans;
  //--------------------------------------------------------------------
}
int main()
{
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  vector<int> ans = maxSlidingWindow(nums, 3);
  printIntVector(ans);
  return 0;
}