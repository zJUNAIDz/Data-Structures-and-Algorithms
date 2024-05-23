#include <iostream>
#include <vector>
using namespace std;

vector<int> generateRow(int row)
{
  vector<int> res = {};
  res.push_back(1);
  int ans = 1;
  for (int i = 1; i < row; i++)
  {
    ans *= row - i;
    ans /= i;
    res.push_back(ans);
  }
  return res;
}

vector<vector<int>> generateTriangle(int row)
{
  vector<vector<int>> ans = {};
  for (int i = 1; i <= row; i++)
    ans.push_back(generateRow(i));
  return ans;
}

int main()
{
  vector<int> ans = generateRow(3);
  for (auto &i : ans)
  {
    cout << i << " ";
  }
  return 0;
}