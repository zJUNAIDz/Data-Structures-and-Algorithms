function characterReplacement(s: string, k: number): number {
  const freq = Array(26).fill(0);
  let maxFreq = 0;
  let res = 0;
  let l = 0;
  for (let r = 0; r < s.length; r++) {
    const idxR = getIdx(s[r]);
    const idxL = getIdx(s[l]);
    freq[idxR]++;
    maxFreq = Math.max(maxFreq, freq[idxR]); // keep track of max frequency in the window

    // check if valid window
    while ((r - l + 1) - maxFreq > k) { // shrink window until valid
      // no need to update maxFreq here as the maxFreq will either stay the same or increase.
      freq[idxL]--; // but gotta keep them window frequency accurate.. it can't get caught lackin
      l++;
    }
    res = Math.max(res, r - l + 1);
  }
  return res;
};

function getIdx(char: string): number {
  return char.charCodeAt(0) - 'A'.charCodeAt(0);
}
