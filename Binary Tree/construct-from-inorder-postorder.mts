// 106. Construct Binary Tree from Inorder and Postorder Traversal [Medium]

class TreeNode {
  val: number;
  left: TreeNode | null;
  right: TreeNode | null;
  constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
  }
}

function buildTree(inorder: number[], postorder: number[]): TreeNode | null {
  let index = postorder.length - 1;
  function solve(inorderStart: number, inorderEnd: number): TreeNode | null {
    if (index < 0 || inorderStart >= inorderEnd) {
      return null;
    }
    const element = postorder[index--];
    const root = new TreeNode(element);
    const idx = inorder.findIndex((item) => item === element);
    root.right = solve(idx + 1, inorderEnd);
    root.left = solve(inorderStart, idx - 1);
    return root;
  }

  const res = solve(0, inorder.length - 1);
  return res;
}

//Test for LC 106. Construct Binary Tree from Inorder and Postorder Traversal
const inorder = [9, 3, 15, 20, 7],
  postorder = [9, 15, 7, 20, 3];
console.log(buildTree(inorder, postorder)); // [3,9,20,null,null,15,7]

