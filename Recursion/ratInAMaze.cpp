#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isSafe(int x, int y, int n, vector<vector<int>> arr,
            vector<vector<int>> visited)
{
  if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 &&
      arr[x][y] == 1)
  {
    return true;
  }
  else
    return false;
}
void solve(vector<vector<int>> arr, int n, int x, int y,
           vector<vector<int>> visited, string path, vector<string> &ans)
{
  // Base Case
  if (x == n - 1 && y == n - 1)
  {
    ans.push_back(path);
    return;
  }
  // Processing
  visited[x][y] = 1;
  // try going up down left right
  // Code for going Down (x,y+1)
  int newX = x;
  int newY = y + 1;
  if (isSafe(newX, newY, n, arr, visited))
  {
    // push letter of direction
    path += "D";
    solve(arr, n, newX, newY, visited, path, ans);
    path.pop_back();
  }

  // Code for going right (x+1,y)

  newX = x + 1;
  newY = y;
  if (isSafe(newX, newY, n, arr, visited))
  {
    // push letter of direction
    path += "R";
    solve(arr, n, newX, newY, visited, path, ans);
    path.pop_back();
  }
  // Code for going left (x-1,y)

  newX = x - 1;
  newY = y;
  if (isSafe(newX, newY, n, arr, visited))
  {
    // push letter of direction
    path += "L";
    solve(arr, n, newX, newY, visited, path, ans);
    path.pop_back();
  }
  // Code for going Up (x,y-1)

  newX = x;
  newY = y - 1;
  if (isSafe(newX, newY, n, arr, visited))
  {
    // push letter of direction
    path += "U";
    solve(arr, n, newX, newY, visited, path, ans);
    path.pop_back();
  }
  // Backtrack for new recursion(path finding)
  visited[x][y] = 0;
}
vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
  vector<string> ans;
  int srcx = 0;
  int srcy = 0;
  //   vector<vector<int>> visited(n*n); // m because we are giving same size as
  //   m
  vector<vector<int>> visited(n, vector<int>(n, 0));

  // initializing each element with 0 in visited
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      visited[i][j] = 0;
  string path = "";
  solve(arr, n, srcx, srcy, visited, path, ans);
  sort(ans.begin(), ans.end());
  return ans;
}
int main()
{

  return 0;
}