#include <iostream>
using namespace std;
void reverse_string(string &str, int s = 0)
{
  // Base Case
  if (s > str.length() - s)
    return;
  // Processing
  swap(str[s], str[str.length() - s - 1]);
  // Recursive Relation
  reverse_string(str, s + 1);
}
int main()
{
  string str = "junaid";
  // we use 2 pointers that we passed in array like reverse_string(str,0,str.;ength()-1)
  // but its not optimized..now we used only one pointer s to find second ponter e (e=str.length-s-1)
  reverse_string(str);
  cout << str;
  return 0;
}