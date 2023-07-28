#include <iostream>
using namespace std;
int power(int x, int y)
{
  // Base Case
  if (y == 0)
    return 1;
  if (y == 1)
    return x;
  // Recursive Relation
  int ans = power(x, y / 2);
  if (y % 2)
    return x * ans * ans;
  else
    return ans * ans;
}
int main()
{
  cout << power(2, 11);
  return 0;
}