// https://www.codingninjas.com/studio/problems/count-ways-to-reach-nth-stairs_798650?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_10

#include <iostream>
using namespace std;
int countDistinctWays(int nStairs)
{
  // base case
  if (nStairs < 0)
    return 0;
  if (nStairs == 0)
    return 1;
  // Recursion case (Recursion relation)
  int ans = countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2);
  return ans;
}
int main()
{

  return 0;
}