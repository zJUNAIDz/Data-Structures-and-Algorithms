#include <iostream>
using namespace std;

int minSubarraySum(int arr[], int n, int k)
{
  // Write your code here
  int temp = 100000;
  for (int i = 0; i < n - 2; i++)
  {
    for (int j = i; j < n - 1; j++)
    {
      for (int k = j; k < n; k++)
      {
        if (arr[i] + arr[j] + arr[k] < temp)
        {
          temp = arr[i] + arr[j] + arr[k];
        }
      }
    }
  }
  return temp;
}

int main()
{
  
  return 0;
}