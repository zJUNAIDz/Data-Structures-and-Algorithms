#include <iostream>
#include <vector>
using namespace std;
void solve(string str, string output, int index, vector<string> &ans)
{
  // Base Case
  if (index >= str.length())
  {
    ans.push_back(output);
    return;
  }
  // Recursive Relation
  // exclude
  solve(str, output, index + 1, ans);
  // include
  int element = str[index];
  output.push_back(element);
  solve(str, output, index + 1, ans);
}
vector<string> subsequences(string str)
{
  vector<string> ans;
  string output;
  solve(str, output, 0, ans);
  return ans;
}
int main()
{

  return 0;
}