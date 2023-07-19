#include <iostream>
#include <string>
using namespace std;
bool permutation(string s1, string s2)
{
  // counts banlo or 0 se fill kardo jo count of letters represent kar raha hoga
  int s1Count[26] = {0};
  // counting s1 (permutaion key string)
  for (int i = 0; i < s1.length(); i++)
  {
    int index = s1[i] - 'a';
    s1Count[index]++;
  }

  // sliding window banado while loop se
  int left = 0;
  int right = s1.length();
  // cout << "right: "<<s2.length() <<endl;
  int ans = true;
  while (right <= s2.length())
  {
    // count for s2 window part
    int s2Count[26] = {0};
    for (int i = left; i <= right; i++)
    {
      int index = s2[i] - 'a';
      s2Count[index]++;
    }
    for (int i = 0; i < 26; i++)
    {
      if (s1Count[i] != s2Count[i])
      {
        ans = false;
        break;
      }
      else
      {
        ans = true;
      }
    }
    if (ans)
      return true;
    else
    {
      left++;
      right++;
    }
  }
  return false;
}
int main()
{
  string s1 = "adc";
  string s2 = "dcda";
  cout << permutation(s1, s2);
  return 0;
}
