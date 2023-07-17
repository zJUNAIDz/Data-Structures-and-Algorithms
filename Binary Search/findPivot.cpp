#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int find_pivot(vector<int> arr)
{
  // implement
  int start = 0;
  int end = arr.size() - 1;
  int mid = start + (end - start) / 2;

  while (start < end)
  {
    if(arr[arr.size()-1] > arr[0]){
      return arr[0];
    }
    else if (arr[mid] >= arr[0])
    {
      start = mid + 1;
    }
    else
    {
      end = mid;

    }
    mid = start + (end - start) / 2;
  }
  return start;
}

int main()
{
  // vector<int> arr = {7, 8, 8, 9, 10, 1, 2, 2, 3, 4, 5, 6};
  vector<int> arr = {3, 4, 5, 1, 2};
  cout << find_pivot(arr) << endl;
  return 0;
}