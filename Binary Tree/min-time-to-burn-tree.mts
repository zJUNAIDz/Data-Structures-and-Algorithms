class Node {
  key: number;
  left: Node | null;
  right: Node | null;
  constructor(x: number) {
    this.key = x;
    this.left = null;
    this.right = null;
  }
}
type NodeToParentMap = Map<Node, Node | null>;
type VisitedMap = Map<Node, boolean>;
function findTargetNode(root: Node | null, target: number): Node | null {
  let result: Node | null = null;
  function solve(root: Node | null) {
    if (root === null || result) return;
    if (root.key === target) {
      console.log("found");
      result = root;
    } else {
      console.log("not found");
      solve(root.left);
      solve(root.right);
    }
  }
  solve(root);
  return result;
}
function mapToParent(root: Node | null, map: NodeToParentMap) {
  if (root === null) return;
  if (root.left !== null) {
    map.set(root.left, root);
  }
  if (root.right !== null) {
    map.set(root.right, root);
  }
  mapToParent(root.left, map);
  mapToParent(root.right, map);
}
function burnTree(root: Node, map: NodeToParentMap): number {
  // make necessary data (queue)
  const queue: Node[] = [root];
  const visited: VisitedMap = new Map();
  visited.set(root, true); //mark root as visited
  let time = 0;
  console.log("BEGINS");
  while (queue.length > 0) {
    console.log({ queueLength: queue.length });
    let isLevelBurnt = false;
    for (let i = 0; i < queue.length; ++i) {
      const node = queue.shift()!;
      const arr = [node?.left, node?.right, map.get(node)];
      for (let item of arr) {
        if (item && !visited.get(item)) {
          queue.push(item);
          visited.set(item, true);
          isLevelBurnt = true;
        }
      }
    }
    isLevelBurnt && time++; // to make sure time is incremented only once per level
  }
  return time;
}
function minTime(root: Node, target: number) {
  //* Step 1. map node to it's parent
  const parentMap: NodeToParentMap = new Map();
  parentMap.set(root, null);
  mapToParent(root, parentMap);

  //* Step 2. Find target Node
  const targetNode = findTargetNode(root, target);
  if (!targetNode) {
    return 0;
  }
  //* Step 3. Burn em down 🔥
  const time = burnTree(targetNode, parentMap);
  return time;
}
//Test GFG Burning Tree
const root = new Node(1);
root.left = new Node(2);
root.right = new Node(3);
root.left.left = new Node(4);
root.left.right = new Node(5);
root.right.left = new Node(6);
root.right.right = new Node(7);
console.log(minTime(root, 2)); // 4
