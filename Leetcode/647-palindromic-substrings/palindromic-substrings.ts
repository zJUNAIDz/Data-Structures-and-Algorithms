function countSubstrings(s: string): number {
  let count: number = 0;
  // for odds
  for (let i = 0; i < s.length; i++) {
    const oddLen = countPossiblePalindrome(i, i, s);
    const evenLen = countPossiblePalindrome(i, i + 1, s);
    count += oddLen + evenLen;
  }
  return count;
};

function countPossiblePalindrome(i: number, j: number, str: string): number {
  let count: number = 0;
  let left = i, right = j;
  while (left >= 0 && right < str.length && str[left] === str[right]) {
    left--;
    right++;
    count++;
  }
  return count;
}

