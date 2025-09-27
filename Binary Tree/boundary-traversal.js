class Node {
  constructor(data) {
    this.data = data;
    this.left = null;
    this.right = null;
  }
}

/**
 * @param {Node} root
 * @returns {number[]}
 */

class Solution {
  leftTraversal(root, ans) {
    if (root === null || (root.left === null && root.right === null)) return;
    ans.push(root.data);
    if (root.left === null) this.leftTraversal(root.right, ans);
    else this.leftTraversal(root.left, ans);
  }
  leafTraversal(root, ans) {
    if (root === null) return;
    if (root.left === null && root.right === null) {
      ans.push(root.data);
      return;
    }
    this.leafTraversal(root.left, ans);
    this.leafTraversal(root.right, ans);
  }
  rightTraversal(root, ans) {
    if (root === null || (root.left === null && root.right === null)) return;
    if (root.right === null) this.rightTraversal(root.left, ans);
    else this.rightTraversal(root.right, ans);
    ans.push(root.data);
  }
  boundaryTraversal(root) {
    const ans = [root.data];
    if (root.left === null && root.right === null) return ans;
    this.leftTraversal(root.left, ans);
    this.leafTraversal(root, ans);
    this.rightTraversal(root.right, ans);
    return ans;
  }
}

//Test
const root = new Node(1);
root.left = new Node(2);
root.right = new Node(3);
root.left.left = new Node(4);
root.left.right = new Node(5);
root.right.left = new Node(6);
root.right.right = new Node(7);
const sol = new Solution();
console.log(sol.boundaryTraversal(root)); // [ 1, 2, 4, 5, 6, 7, 3 ]
