function networkDelayTime(times: number[][], n: number, k: number): number {
  const adj: Map<number, [number, number][]> = new Map();
  //make adjacency list
  for (const [u, v, w] of times) {
    if (!adj.has(u)) {
      adj.set(u, []);
    }
    adj.get(u)!.push([v, w]);
  }
  const distances:number[] = Array(n + 1).fill(Infinity); // storing shortest path(value) to the node(represented by idx) from k(root)
  distances[k] = 0; // origin is always 0 distance
  const pq = new MinPriorityQueue<[number, number]>((val) => val[1]); // keeping track of shortest path found so far 
  pq.enqueue([k, 0])

  while (pq.size() > 0) {
    const [currNode, currTime] = pq.dequeue()!;

    // Optimization skipping if we've already fiound shorted path to currNode
    if (currTime > distances[currNode]) continue; 

    if (!adj.has(currNode)) continue; // no neighbor

    // for each neighbor, we check if the distnce to neighbor from k (weight from currNode to nei(wei) + distance from k to currNode (distances[currNode])) is less than currently found distance (distances[nei] which could be Infinity initially so it will be updated to new val or else only if shorter found), we update the distances[nei] and add new distance to pq for further processing 
    for (const [nei, wei] of adj.get(currNode)!) {
      const dist:number = distances[currNode] + wei;
      if (dist < distances[nei]) {
        distances[nei] = dist;
        pq.enqueue([nei, distances[nei]])
      }
    }
  }
  const maxTime = Math.max(...distances.slice(1)); // we don't use o-based indexing for simplicity
  return maxTime === Infinity ? -1 : maxTime; // if any of them is still Infinity then that node is not reachable
};