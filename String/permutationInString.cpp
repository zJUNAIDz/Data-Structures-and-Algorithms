#include <iostream>
using namespace std;

class Solution
{
  // generalised array equality checker
  // n=length of arr1
  // m=length of arr2
private:
  int isEqual(int arr1[], int arr2[])
  {
    for (int i = 0; i < 26; i++)
      if (arr1[i] != arr2[i])
        return false;
    return true;
  }

public:
  bool checkInclusion(string s1, string s2)
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
      // check equality
      if (isEqual(s1Count, s2Count))
        return true;
      left++;
      right++;
    }
    return false;
  }
};

int main()
{
  Solution s;
  cout << s.checkInclusion("ba", "aibaaoo");
  return 0;
}