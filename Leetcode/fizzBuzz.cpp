#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> fizzBuzz(int n)
{
  vector<string> answer;
  for (int i = 0; i < n; i++)
  {
    if (i % 3 == 0 && i % 5 == 0)
    {
      answer[i] = "FizzBuzz";
    }
    else if (i % 3 == 0)
    {
      answer[i] = "Fizz";
    }
    else if (i % 5 == 0)
    {
      answer[i] = "Buzz";
    }
    else
    {
      answer[i] = to_string(i);
    }
  }
  return answer;
}
int main()
{

  return 0;
}