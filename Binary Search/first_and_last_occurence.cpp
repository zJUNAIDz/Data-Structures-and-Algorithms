#include <iostream>
#include <utility>
using namespace std;

pair<int, int> findOccurences(int arr[], int n, int k)
{
  // Most optimal solution is using Binary search
  // Binary search variables
  int start = 0;
  int end = n - 1;
  long int mid = start + (end - start) / 2;
  while (start < end)
  {
    if (arr[mid] == k)
    {
      // cout << mid;
      int left = mid - 1;
      int right = mid + 1;
      while (arr[left] == arr[right])
      {
        if (arr[left] == k)
          left--;
        else if (arr[right] == k)
          right++;
      }
      cout << left + 1 << ' ' << right << endl;
      return make_pair(left, right);
      // return make_pair(left, right);
    }
    else if (arr[mid] < k)
    {
      start = mid+1; //or maybe mid only
      mid = (start + end) / 2;
    }
    else if (arr[mid] > k)
    {
      end = mid-1; //or maybe mid only
      mid = (start + end) / 2;
    }
  }
  return {-1, -1};
}

int main()
{
  int arr[] = {1, 2, 3, 4, 4, 4, 4, 5, 6, 6, 7, 8};

  findOccurences(arr, 12, 4);

  return 0;
}
