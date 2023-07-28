#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> &boards, int k, int mid)
{
  // pehli baat toh yeh k apne paas 2 painters hai
  int paintersCount = 1;
  int currSum = 0;
  int len = boards.size();
  int it = 1;

  for (int i = 0; i < len; i++)
  {
    cout << "Iteration : " << it++ << endl;
    cout << "mid : " << mid << endl;
    if (currSum + boards[i] <= mid)
    {
      cout << "in if" << endl;
      cout << "  painterscount : " << paintersCount << endl;
      cout << "  currSum before : " << currSum << endl;
      currSum += boards[i];
      cout << "  currSum after : " << currSum << endl;
    }
    else
    {
      cout << "in else" << endl;
      cout << "  currSum before : " << currSum << endl;
      currSum = boards[i];
      cout << "  currSum after : " << currSum << endl;
      cout << "  painterscount before : " << paintersCount << endl;
      paintersCount++;
      cout << "  painterscount after : " << paintersCount << endl;
    }
    if (boards[i] > mid)
      return false;
    if (paintersCount > k)
      return false;
  }
  return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
  // search space nikalo
  sort(boards.begin(), boards.end());
  int start = 0;
  int end = 0;
  for (int i = 0; i < boards.size(); i++)
  {
    end += boards[i];
  }
  // cout << end << endl;
  int mid = start + (end - start) / 2;
  int ans = -1;
  while (start <= end)
  {

    // As we have to find Largest minimum Distance, we have to search in right part
    //  if its a possible solution

    if (isPossible(boards, k, mid))
    {
      // cout << "in if" << endl;
      ans = mid;
      // start = mid + 1;
      end = mid - 1;
    }
    else
    {
      // cout << " in else" << endl;

      // end = mid - 1;
      start = mid + 1;
    }
    mid = start + (end - start) / 2;
  }
  return ans;
}

int main()
{
  vector<int> arr1 = {5, 5, 5, 5};
  vector<int> arr2 = {10, 20, 30, 40};
  vector<int> arr3 = {2, 9, 2, 4, 5, 10, 3, 3, 4, 1};
  int len = 4;
  int k = 2;

  cout << findLargestMinDistance(arr3, k);
  return 0;
}