#include <iostream>
#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
  // but this time we will go with row and column first
  int row = matrix.size();
  int col = matrix[0].size();
  // regular binary search variables
  // we are supposing it to be linear array in terms of index
  // then later we will figure out the 2D version of mid when we find the key
  int start = 0;
  int end = row * col - 1; // yeah remember this trick
  // simply while loop chala do
  int i = 1;
  while (start <= end)
  {
    int mid = start + (end - start) / 2;
    // 2D version of index
    int element = matrix[mid / col][mid % col];
    // if key is found
    if (element == target)
      return 1;
    if (element < target)
      start = mid + 1;
    else
      end = mid - 1;
  }
  return 0;
}
int main()
{
  vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  cout << searchMatrix(matrix, 3);
  return 0;
}
