
class TrieNode {
  public children: Map<string, TrieNode>;
  public word: string | null; // store word at the end node
  constructor() {
    this.children = new Map();
    this.word = null;
  }
}
function findWords(board: string[][], words: string[]): string[] {
  const trie = buildTrie(words);
  const result:string[] = [];// could use set to avoid duplicates but this is handled in dfs by marking found words as null

  for (let i = 0; i < board.length; i++) {
    for (let j = 0; j < board[0].length; j++) {
      if (!trie.children.has(board[i][j])) {// if no matching child, skip
        continue;
      }
      dfs(board, trie, i, j, result);
    }
  }
  return result
};

function dfs(board: string[][], trie: TrieNode, i: number, j: number, result: string[]) {

  // out of bounds or visited
  if (
    i < 0 ||
    j < 0 ||
    i >= board.length ||
    j >= board[0].length ||
    board[i][j] === '#'
  ) {
    return;
  }
  const char = board[i][j];
  // no matching child so no point to continue
  if (!trie.children.has(char)) {
    return;
  }
  const childNode = trie.children.get(char)!;
  if (childNode.word !== null) {
    result.push(childNode.word);
    childNode.word = null; // avoid duplicate
  }
  // mark as visited [baktracking]
  board[i][j] = "#"
  const dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]]
  for (const [dx, dy] of dirs) {// explore 4 directions
    dfs(board, trie.children.get(char)!, i + dx, j + dy, result);
  }
  // mark as unvisited
  board[i][j] = char;
}
// simply builds and returns trie from array of words
function buildTrie(words: string[]): TrieNode {
  const trie = new TrieNode();
  for (const word of words) {
    let node = trie;
    for (const char of word) {
      if (!node.children.has(char)) {
        node.children.set(char, new TrieNode());
      }
      node = node.children.get(char)!;
    }
    node.word = word;// save word at the end node
  }
  return trie;
}

