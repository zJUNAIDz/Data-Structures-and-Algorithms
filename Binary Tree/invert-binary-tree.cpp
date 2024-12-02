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

void solve(TreeNode *root)
{
  if (root == NULL)
    return;
  if (root->left)
    solve(root->left);
  if (root->right)
    solve(root->right);
  TreeNode *temp = root->left;
  root->left = root->right;
  root->right = temp;
}
TreeNode *invertTree(TreeNode *root)
{
  solve(root);
  return root;
}

int main()
{
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(20);
  root->right = new TreeNode(30);
  root->right->left = new TreeNode(40);

  TreeNode *invertedRoot = invertTree(root);
  return 0;
}