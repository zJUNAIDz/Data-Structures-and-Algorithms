#include <iostream>
using namespace std;

class Solution
{
public:
  bool checkInclusion(string s1, string s2)
  {
    int count[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
      int index = s1[1] - 'a';
      count[index]++;
    }
    // using sliding windows approach to detect permutation in string
    int i = 0;
    int windowSize = s1.length();
    

  }
};

int main()
{
  Solution s;
  cout << s.checkInclusion("ba", "aibaaoo");
  return 0;
}