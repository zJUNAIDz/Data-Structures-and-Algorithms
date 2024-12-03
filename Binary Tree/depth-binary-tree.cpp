#include <iostream>
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

int solve(TreeNode *curr)
{
  if (curr == NULL)
    return 0;
  return (1 + max(solve(curr->left), solve(curr->right)));
}

int maxDepth(TreeNode *root)
{
  return solve(root);
}

int main()
{
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(20);
  root->right = new TreeNode(30);
  root->right->left = new TreeNode(40);
  cout << "Max Depth: " << maxDepth(root) << endl;
  return 0;
}