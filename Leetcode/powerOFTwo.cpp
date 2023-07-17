#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
  bool isPowerOfTwo(int n)
  {
    for (int i = 0; i <= 31; i++)
    {
      if (pow(2, i) == n)
        return true;
    }
    return false;
  }
};

int main()
{
  Solution obj;
  cout << obj.isPowerOfTwo(-64);
  return 0;
}