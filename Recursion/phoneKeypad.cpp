/*
 *LC - 17. Letter Combinations of a Phone Number
 */
#include <iostream>
#include <vector>
using namespace std;
void solve(string digits, string keyMap[], string output, int index, vector<string> &ans)
{
  // Base Case
  if (index >= digits.length())
  {
    ans.push_back(output);
    return;
  }

  // index pointing to which number
  int number = digits[index] - '0';
  string keyValue = keyMap[number];
  // keyValue k elemnts ko traverse karke sab ke liye recursive call maardo
  for (int i = 0; i < keyValue.length(); i++)
  {
    output.push_back(keyValue[i]);
    solve(digits, keyMap, output, index + 1, ans);
    output.pop_back(); // Backtracking hori hai bhay bhot zorr se
  }
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
  solve(digits, keyMap, output, index, ans);
}
int main()
{

  return 0;
}