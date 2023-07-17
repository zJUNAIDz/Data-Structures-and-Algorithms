#include <iostream>
using namespace std;
int getSum(int *arr, int n)
{
  int sum = 0;
  for (int i = 0; i <= n; i++)
  {
    sum += arr[i];
  }
  return sum;
}
int main()
{
  int n;
  cin >> n;

  // Variable sized Array
  int *arr = new int[n];
  for (int i = 0; i <= n; i++)
  {
    cin >> arr[i];
  }
  cout << getSum(arr, n) << endl;
  return 0;
}