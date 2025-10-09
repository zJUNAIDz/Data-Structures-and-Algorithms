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
//* Morris Traversal

/**
 * How it works?
 * 1. Start from the root node and initialize a pointer `current` to the root.
 * 2. While `current` is not null, do the following:
 *   a. If `current` has a left child:
 *       i. Find the rightmost node in the left subtree of `current` (let's call it `prev`).
 *      ii. Set the right child of `prev` to point to the right child of `current`.
 *     iii. Move the left child of `current` to be the right child of `current`.
 *    iv. Set the left child of `current` to null.
 *  b. Move `current` to its right child.
 * 3. Repeat until `current` becomes null.
 * This process effectively flattens the tree in place, transforming it into a linked list.
 */
function flatten(root: TreeNode | null): void {
  let current = root;
  let prev: TreeNode | null = null;
  while (current !== null) {
    if (current.left !== null) {
      prev = current.left;
      while (prev.right !== null) {
        prev = prev?.right;
      }
      prev.right = current.right;
      current.right = current.left;
      current.left = null;
    }
    current = current.right;
  }
}

// Test
const root = new TreeNode(1);
root.left = new TreeNode(2);
root.right = new TreeNode(5);
root.left.left = new TreeNode(3);
root.left.right = new TreeNode(4);
root.right.right = new TreeNode(6);

flatten(root);
//print values
let curr: TreeNode | null = root;
const result: number[] = [];
while (curr !== null) {
  result.push(curr.val);
  curr = curr.right;
}
console.log(result);
// Output: [1,2,3,4,5,6]
