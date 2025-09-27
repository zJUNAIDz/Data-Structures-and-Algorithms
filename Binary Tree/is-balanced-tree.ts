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

function isBalanced(root: TreeNode | null): boolean {
  function height(root: TreeNode | null): number {
    if (root === null) {
      return 0;
    }
    const left = height(root.left);
    if (left === -1) return -1;
    const right = height(root.right);
    if (right === -1) return -1;
    if (Math.abs(left - right) > 1) return -1;

    const h = Math.max(left, right) + 1;
    // console.log({ left, right, diff: Math.abs(left - right), ans });
    return h;
  }
  return height(root) !== -1;
}
//test
//[3,9,20,null,null,15,7]
const tree = new TreeNode(3);
tree.left = new TreeNode(9);
tree.right = new TreeNode(20);
tree.right.left = new TreeNode(15);
tree.right.right = new TreeNode(7);
console.log(isBalanced(tree));
