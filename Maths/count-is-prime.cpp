#include <iostream>
using namespace std;
class Solution
{
private:
  bool isPrime(int n)
  {
    if (n <= 1)
    {
      return false;
    }
    for (int i = 2; i < n; i++)
    {
      if (n % i == 0)
      {
        return false;
      }
    }
    return true;
  }

public:
  int countPrime(int n)
  {
    int count = 0;
    for (int i = 2; i <= n; i++)
    {
      if (isPrime(n))
        count++;
    }
    return count;
  }
};

int main()
{
  Solution s;
  cout << s.countPrime(10) << endl;
}