//* 287. Find the Duplicate Number
//
// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
//
// There is only one repeated number in nums, return this repeated number.
//
// You must solve the problem without modifying the array nums and uses only constant extra space.
//

#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
using namespace std;

int findDuplicate(vector<int> &nums)
{
  unordered_set<int> seen;
  int len = nums.size();
  for (int i = 0; i < len; i++)
  {
    int curr = nums[i];
    if (seen.count(curr))
      return curr;
    seen.insert(curr);
  }
  return -1;
}

int main()
{

  return 0;
}