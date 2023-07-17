#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
  int reverse(int x)
  {
    int ans = 0;
    while (x)
    {
      ans = ans * 10 + x % 10;
      x /= 10;
    }
    return ans;
  }
};
int main()
{
  Solution obj;
  cout <<  obj.reverse(4321);
  return 0;
}