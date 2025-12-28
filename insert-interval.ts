function insert(intervals: number[][], newInterval: number[]): number[][] {
  const res: number[][] = [];
  let [ns, ne] = newInterval;
  let inserted = false;
  for (const [start, end] of intervals) {
    if (end < ns) {

      res.push([start, end]);
      continue;
    }
    if (start > ne) {
      if (!inserted) {
        res.push([ns, ne]);
        inserted = true;
      }
      res.push([ns, ne])
    }
    if (end >= ns) {
      ns = Math.min(ns, start);
    }
    if (start <= ne) {
      ne = Math.max(ne, end);
    }
  }
  if (!inserted) {
    res.push([ns, ne])
  }
  return res;
};

