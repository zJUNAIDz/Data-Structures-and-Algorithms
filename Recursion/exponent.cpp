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
  if (y % 2)
    return x * (power(x, y / 2) * power(x, y / 2));
  else
    return power(x, y / 2) * power(x, y / 2);
}
int main()
{
  cout << power(2, 11);
  return 0;
}