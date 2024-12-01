#include <iostream>
#include <vector>
using namespace std;
bool isAnagram(string s, string t)
{
  vector<int> freq(26, 0);
  // store size to avoid redundant computation in loop coditions
  int sSize = s.size();
  int tSize = t.size();
  // early return if string length doesn't match
  if (sSize != tSize)
    return false;

  for (int i = 0; i < sSize; i++)
  {
    int index = s[i] - 'a';
    freq[index]++;
  }
  for (int i = 0; i < tSize; i++)
  {
    int index = t[i] - 'a';
    freq[index]--;
  }

  int freqSize = freq.size();
  for (int count : freq)
    if (count != 0)
      return false;
  return true;
}
int main()
{
  char str = 'a';
  cout << (int)str;
  return 0;
}