#include <iostream>
#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
  // but this time we will go with row and column first
  int row = matrix.size();
  int col = matrix[0].size();
  // regular binary search variables
  //we are supposing it to be linear array in terms of index 
  //then later we will figure out the 2D version of mid when we find the key
  int start = 0;
  int end = row * col - 1; // yeah remember this trick
  int mid = start + (end - start) / 2;
  //simply while loop chala do
  while(start<end){
    
  }
}
int main()
{

  return 0;
}