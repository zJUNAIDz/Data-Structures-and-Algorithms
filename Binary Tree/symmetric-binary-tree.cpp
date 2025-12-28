#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isPalindrome(vector<int> arr)
{
  int arrSize = arr.size();
  if (arrSize == 1 || arrSize == 0)
    return true;
  int firstIndex = 0;
  int lastIndex = arr.size();
  while (firstIndex < lastIndex)
  {
    if (arr[firstIndex++] != arr[lastIndex++])
      return false;
  }
  return true;
}

vector<vector<int>> levelOrder(TreeNode *root)
{
  vector<vector<int>> ans;
  if (root == NULL)
    return ans;
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty())
  {
    int size = q.size();
    vector<int> level;
    for (int i = 0; i < size; i++)
    {
      TreeNode *node = q.front();
      q.pop();
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
      level.push_back(node->val);
    }
    ans.push_back(level);
  }
  return ans;
}

bool isSymmetric(TreeNode *root)
{
  vector<vector<int>> levels = levelOrder(root);
  int levelsLength = levels.size();
  for (int i = 0; i < levelsLength; i++)
  {
    vector<int> level = levels[i];
    if (!isPalindrome(level))
      return false;
  }
  return true;
}

int main()
{

  return 0;
}