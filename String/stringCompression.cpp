#include <iostream>
#include <vector>
#include <string>
using namespace std;

int compress(vector<char> &chars)
{
  int count = 1;
  char currChar = chars[0];
  string ans = "";
  if (chars.size() == 1)
    return chars[0];
  // cout << "char size:" << chars.size() << endl;
  for (int i = 1; i < chars.size(); i++)
  {
    if (chars[i] != currChar)
    {
      ans.push_back(currChar);
      if (count > 1)
      {
        string strCount = to_string(count);
        ans += strCount;
      }
      currChar = chars[i];
      count = 1;
    }
    else
      count++;
    if (i == chars.size() - 1)
    {
      ans.push_back(currChar);
      // count++;
      if (count > 1)
      {
        string strCount = to_string(count);
        ans += strCount;
      }
    }
  }

  // ab ans string ko chars mein daaldo
  // sabse pehle chars ko khali karo
  chars.clear();
  // cout << "ans " << ans << endl;
  // ab saare ans elements ko traverse karke chars mein push back karo
  for (int i = 0; i <= ans.length(); i++)
  {
    // cout << "i : " << i << endl;
    chars.push_back(ans[i]);
    cout << chars[i] << ' ';
  }
  // cout << endl;
  return ans.length();
}

int main()
{
  // vector<char> chars = {'a', 'a', 'b', 'b', 'b', 'c', 'c', 'c', 'c'};
  vector<char> chars = {'a', 'b', 'c'};
  cout << compress(chars);
  return 0;
}
