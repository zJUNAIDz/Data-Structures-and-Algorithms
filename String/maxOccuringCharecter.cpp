#include <iostream>
#include <string.h>
using namespace std;

int getMaxOccChar(string s)
{
  int arr[26] = {0};
  for (int i = 0; i < s.length(); i++)
  {
    char ch = s[i];
    int number = -1;
    if (ch >= 'a' && ch <= 'z')
    {
      number = ch - 'a';
    }
    else
    {
      number = ch - 'A';
    }
    arr[number]++;
  }
  int maxIndex = -1;
  for (int i = 0; i < 26; i++)
  {
  }
}

int main()
{
  string s = "there must be a charecter occuring maximum number of times";
  return 0;
}