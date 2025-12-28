function partition(s: string): string[][] {
  const res: string[][] = [];
  const path: string[] = [];
  function isPalindrome(i: number, j: number): boolean {
    while (i < j) {
      if (s[i++] !== s[j--]) {
        return false;
      }
    }
    return true;
  }
  function dfs(start: number) {
    if (start === s.length) {
      res.push([...path])
      return;
    }
    for (let end = start; end < s.length; end++) {
      if (isPalindrome(start, end)) {
        path.push(s.slice(start, end + 1))
        dfs(end + 1);
        path.pop();
      }
    }
  }
  dfs(0);
  return res;
};

