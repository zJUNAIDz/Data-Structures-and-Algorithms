#include <iostream>
#include <string>
using namespace std;
string fetchWord(string str, int &index)
{
  string ans = "";
  while (str[index] != ' ' && index != str.length())
  {
    ans += str[index++];
  }
  return ans;
}
string reverseString(string &str)
{
  // Write your code here.
  int index = 0;
  string ans = "";
  while (index < str.length())
  {

    string word = fetchWord(str, index);
    for (int i = word.length() - 1; i >= 0; i--)
    {

      ans += word[i];
    }
    if (index < str.length())
      ans += " ";
    index++;
  }
  return ans;
}
int main()
{
  string str = "hello world words so many";
  cout << reverseString(str);
  return 0;
}