#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isPossible(vector<int> &stalls, int k, int mid)
{
  int len = stalls.size();
  int cowCount = 1;
  int lastPos = stalls[0];
  for (int i = 0; i < len; i++)
    if (stalls[i] - lastPos >= mid)
    {
      cowCount++;
      if (cowCount == k)
        return true;
      lastPos = stalls[i];
    }
  return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
  int len = stalls.size();
  sort(stalls.begin(), stalls.end());
  int sum = -1;
  for (int i = 0; i < len; i++)
    sum = max(sum, stalls[i]);
  // binary search variables
  int start = 0;
  int end = sum;

  int ans = -1;
  int mid = start + (end - start) / 2;
  while (start < end)
  {
    if (isPossible(stalls, k, mid))
    {
      ans = mid;
      start = mid + 1;
    }
    else
      end = mid - 1;
    mid = start + (end - start) / 2;
  }
  return ans;
}

int main()
{
  vector<int> stalls = {4, 2, 1, 3, 6};
  cout << aggressiveCows(stalls, 2) << endl;
  return 0;
}