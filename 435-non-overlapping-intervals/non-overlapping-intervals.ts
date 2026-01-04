function eraseOverlapIntervals(intervals: number[][]): number {
  intervals.sort((a, b) => a[1] - b[1]); // sorting intervals by end in non-decreasing order so that we get intervals that finishes soonest..
  let removed = 0;
  let lastEnd = -Infinity;
  for (const [start, end] of intervals) {
    if (start >= lastEnd) { // if no overlap then fine ofc
      lastEnd = end;
    } else { // or else remove it #greedy part, removing current overlapping 
      removed++;
    }
  }
  return removed;
};
