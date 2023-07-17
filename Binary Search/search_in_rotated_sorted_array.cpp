#include <iostream>
#include <vector>
using namespace std;

int getPivot(vector<int> arr, int n)
{
  int s = 0;
  int e = n - 1;
  int mid = s + (e - s) / 2;

  while (s < e)
  {
    if (arr[s] >= arr[0])
      s = mid + 1;
    else
      e = mid;
    mid = s + (e - s) / 2;
  }
  return s;
}
int binarySearch(vector<int> arr, int s, int e, int k)
{
  int mid = s + (e - s) / 2;
  while (s <= e)
  {
    if (arr[mid] == k)
      return mid;
    if (arr[mid] < k)
      s = mid + 1;
    else
      e = mid - 1;
    mid = s + (e - s) / 2;
  }
  return -1;
}
int findPosition(vector<int> arr, int k)
{
  int pivot = getPivot(arr, arr.size());
  cout << "pivot : " << pivot << endl;
  if (k >= arr[pivot] && arr[arr.size() - 1] >= k)
  {
    // searching on second line
    return binarySearch(arr, pivot, n - 1, k);
  }
  else
  {
    // searching on first line
    return binarySearch(arr, 0, pivot - 1, k);
  }
}
int main()
{
  vector<int> arr = {7, 9, 12, 23, 24, 1, 3, 4, 5, 6};
  cout << findPosition(arr, arr.size(), 6);
  return 0;
}