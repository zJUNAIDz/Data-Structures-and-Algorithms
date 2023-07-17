#include <iostream>
#include <vector>
using namespace std;
int peak_element(vector<int> arr)
{
  // binary searching variable
  int start = 0;
  int end = arr.size() - 1;
  int mid = start + (end - start) / 2;
  while (start < end)
  {
    if (arr[mid] < arr[mid + 1])
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
  vector<int> arr = {24, 69, 100, 99, 79, 78, 67, 36, 26, 19};
  cout << peak_element(arr);
  return 0;
}
