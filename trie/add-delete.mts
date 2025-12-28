class Node {
  public children: Map<string, Node>;
  public isEndOfWord: boolean;
  constructor() {
    this.children = new Map();
    this.isEndOfWord = false;
  }
}
class WordDictionary {
  private trie = new Node();
  constructor() {

  }

  addWord(word: string): void {
    let node = this.trie;
    for (const char of word) {
      if (!node.children.has(char)) {
        node.children.set(char, new Node());
      }
      node = node.children.get(char)!;
    }
    node.isEndOfWord = true;
  }

  search(word: string): boolean {

  }
  dfs(node: Node, word: string, i: number) {
    if (i === word.length) {
      return node.isEndOfWord;
    }
    if (word[i] === ".") {
      for (const char of node.children.values()) {
        if (this.dfs(char, word, i + 1)) {
          return true;
        }
        return false;
      }
    }
    if (!node.children.has(word[i])) {
      return false;
    }
    return this.dfs(node.children.get(word[i]), word, i + 1);
  }
}


/**
 * Your WordDictionary object will be instantiated and called as such:
 * var obj = new WordDictionary()
 * obj.addWord(word)
 * var param_2 = obj.search(word)
 */
