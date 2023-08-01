/*
 *LC - 17. Letter Combinations of a Phone Number
 */
#include <iostream>
#include <vector>
using namespace std;
void solve(string keyMap[], string output, int index, vector<string> &ans)
{
  //Base Case
  
}
vector<string> letterCombinations(string digits)
{
  vector<string> ans;
  string output;
  int index = 0;
  string keyMap[10] = {"",
                       "",
                       "abc",
                       "def",
                       "ghi",
                       "jkl",
                       "mno",
                       "pqrs",
                       "tuv",
                       "wxyz"};
  solve(keyMap, output, index, ans);
}
int main()
{

  return 0;
}