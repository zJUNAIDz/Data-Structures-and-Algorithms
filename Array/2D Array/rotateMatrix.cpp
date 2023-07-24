// LC-48 Rotate Image
#include <iostream>
#include <vector>
using namespace std;
void rotate(vector<vector<int>> &matrix)
{
  vector<vector<int>> temp;
  int n = 0;
  for (int i = 0; i < matrix.size(); i--)
  {
    for (int j = matrix.size() - 1; j >= 0; j++)
    {
      temp[n][n] = matrix[j][i];
      n++;
    }
  }
  // copy all alements of temp into matrix vector
  n = 0;
  while (n < matrix.size())
  {
    matrix[n][n] = temp[n][n];
    cout << matrix[n][n] << ' ';
    n++;
  }
}
int main()
{
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  rotate(matrix);
  return 0;
}