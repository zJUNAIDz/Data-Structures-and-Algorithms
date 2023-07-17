#include <iostream>
using namespace std;
class Solution
{
public:
  int bitwiseComplement(int n)
  {
    // mask banado bhaiyya
    int mask = 0;
    int temp = n;
    while (temp)
    {
      temp >>= 1;
      mask = (mask << 1) | 1;
    }
    return (~n & mask);
  }
};

int main()
{
  Solution obj;
  obj.bitwiseComplement(5);
  return 0;
}