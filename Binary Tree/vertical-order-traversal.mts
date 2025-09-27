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

type Data = { val: number; x: number; y: number };
function verticalTraversal(root: TreeNode | null): number[][] {
  //DFS to add all of em
  const nodes: Data[] = [];
  function dfs(root: TreeNode | null, x: number, y: number): void {
    if (root === null) return;
    nodes.push({ val: root.val, x: x, y: y });
    dfs(root.left, x + 1, y - 1);
    dfs(root.right, x + 1, y + 1);
  }
  dfs(root, 0, 0);
  //sort
  nodes.sort((a, b) => {
    if (a.y !== b.y) return a.y - b.y;
    if (a.x !== b.x) return a.x - b.x;
    return a.val - b.val;
  });
  const result = [];
  let currentY = nodes[0].y;
  const group = [];
  for (let n of nodes) {
    if (n.y !== currentY) {
      result.push([...group]);
      group.length = 0;
      currentY = n.y;
    }
    group.push(n.val);
  }
  result.push([...group]);
  return result;
}
//Test for LC 987. Vertical Order Traversal of a Binary Tree
const tree = new TreeNode(3);
tree.left = new TreeNode(9);
tree.right = new TreeNode(20);
tree.right.left = new TreeNode(15);
tree.right.right = new TreeNode(7);
console.log(verticalTraversal(tree)); //[[9],[3,15],[20],[7]]