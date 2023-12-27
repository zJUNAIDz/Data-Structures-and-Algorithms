#include <iostream>
#include <stack>
using namespace std;
int main()
{
  string str = "Junaid";
  stack<char> s;
  cout << "Original: " << str << endl;

  //* inserting characters to stack (LtR)
  for (int i = 0; i < str.length(); i++)
    s.push(str[i]);

  //* popping and storing in result

  string result = "";
  while (!s.empty())
  {
    result.push_back(s.top());
    s.pop();
  }
  cout << "Reversed: " << result << endl;
  return 0;
}