#include <iostream>
using namespace std;
bool isPalindrome(string str, int pointer = 0)
{
  int s = pointer;
  int e = str.length() - s - 1;
  if (s > e)
  {
    return true;
  }
  if (str[s] != str[e])
    return false;
  else
    return isPalindrome(str, pointer + 1);
}
int main()
{
  string str = "aaa";
  bool ans = isPalindrome(str);
  cout << ans;
  return 0;
}