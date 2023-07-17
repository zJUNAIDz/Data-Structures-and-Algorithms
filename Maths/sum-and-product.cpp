#include <iostream>
using namespace std;
class Solution
{
public:
  int prod = 1, sum = 0;
  int subtractProductAndSum(int n)
  {

    if (!n)
      return prod - sum;
      sum += n % 10;
      prod *= n % 10;
      n /= 10;
      return subtractProductAndSum(n);
    
  }
};
int main()
{
  Solution obj;
  cout << obj.subtractProductAndSum(234);
  return 0;
}