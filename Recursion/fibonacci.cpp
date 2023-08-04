#include <iostream>
#include <vector>
using namespace std;
// void fibonacci(vector<int> &arr, int n, int m, int i, int limit)
// {
//   // Base Case
//   if (arr.size() == limit)
//   {
//     return;
//   }
//   // processing
//   arr.push_back(arr[i - 2] + arr[i - 1]);
//   // Recursive Relation
//   fibonacci(arr, arr[i - 1], arr[i], i + 1, limit);
// }

int fibonacci(int n)
{
  // Base Case
  if (n == 0 || n == 1)
  {
    return n;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
  vector<int> arr = {0, 1};
  int limit = 10;
  // fibonacci(arr, arr[0], arr[1], 2, limit);
  for (int i = 0; i < limit; i++)
  {
    cout << fibonacci(i) << ' ';
  }
  // print

  return 0;
}