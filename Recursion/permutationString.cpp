#include <iostream>
#include <vector>
using namespace std;
void solve(vector<int> nums, int index, vector<vector<int>> &ans)
{
  // Base Case
  if (index >= nums.size() - 1)
  {
    ans.push_back(nums);
    return;
  }

  // Recursive Relation

  for (int j = index; j < nums.size(); j++)
  {
    swap(nums[index], nums[j]);
    solve(nums, index + 1, ans);
  }
}
vector<vector<int>> permute(vector<int> &nums)
{
  if(nums.size()==1)
    return {nums};
  vector<vector<int>> ans;
  vector<int> output;
  int index = 0;
  solve(nums, index, ans);
  return ans;
} 
int main()
{

  return 0;
}