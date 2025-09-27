class Node {
  data: number;
  left: Node | null;
  right: Node | null;
  constructor(data: number) {
    this.data = data;
    this.left = null;
    this.right = null;
  }
}

//Morris inorder Traversal
function inorder(root: Node) {
  const result = [];
  let current: Node | null = root;
  while (current !== null) {
    if (current.left === null) {
      result.push(current.data);
      current = current.right;
    } else {
      let predecessor: Node | null = current.left;
      while (predecessor.right !== null && predecessor.right !== current) {
        predecessor = predecessor.right;
      }
      if (predecessor.right === null) {
        predecessor.right = current;
        current = current.left;
      } else {
        predecessor.right = null;
        result.push(current.data);
        current = current.right;
      }
    }
  }
  return result;
}

//Test Morris Inorder Traversal
const root = new Node(1);
root.left = new Node(2);
root.right = new Node(3);
root.left.left = new Node(4);
root.left.right = new Node(5);

console.log(inorder(root)); // Output: [4, 2, 5, 1, 3]