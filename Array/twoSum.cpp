#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, int>> twoSum(vector<int> &arr, int target, int n)
{
  vector<pair<int, int>> ans;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; i < n; j++)
    {
      if (arr[i] + arr[j] == target)
      {
        pair<int, int> temp;
        temp.first = arr[i];
        temp.second = arr[j];
        ans.push_back(temp);
      }
    }
  }
  return ans;
}

int main()
{
  
  return 0;
}