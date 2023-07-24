// LC-240
#include <iostream>
#include <vector>
using namespace std;
bool searchInMatrix(vector<vector<int>> &matrix, int target)
{
  // info about matrix...
  // length of row and column
  int row = matrix.size();
  int col = matrix[0].size();

  // setting index positions of row and column so we can iterate
  int rowIndex = 0;
  int colIndex = col - 1;
  // while loop chala do
  while (rowIndex < row && colIndex >= 0)
  {
    int element = matrix[rowIndex][colIndex];
    // if target is found
    if (element == target)
      return true;
    if (element < target)
      rowIndex++;
    if (element > target)
      colIndex--;
  }
  return false;
}
int main()
{
  vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
  cout << searchInMatrix(matrix, 40);
  return 0;
}
