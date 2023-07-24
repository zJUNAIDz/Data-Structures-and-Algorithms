#include <iostream>
using namespace std;
long long int factorial(int n)
{
  if (n == 0)
    return 1;
  long long int ans = n * factorial(n - 1);
  return ans;
}
int main()
{
  cout << factorial(20);
  return 0;
}