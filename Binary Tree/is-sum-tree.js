class Node {
  constructor(x) {
    this.key = x;
    this.left = null;
    this.right = null;
  }
}

function isSumTree(root) {
  function solve(root) {
    if (root === null) {
      return 0;
    }
    const left = solve(root.left);
    if (left === -1) return -1;
    const right = solve(root.right);
    if (right === -1) return -1;
    const sum = left + right;
    if (sum !== root.key && (root.left !== null || root.right !== null)) {
      return -1;
    }
    const ans = left + right + root.key;
    console.log({ left, right, key: root.key, ans });
    return ans;
  }
  return solve(root) !== -1;
}

// test 3 1 2
const root = new Node(3);
root.left = new Node(1);
root.right = new Node(2);

console.log(isSumTree(root)); // true

 
