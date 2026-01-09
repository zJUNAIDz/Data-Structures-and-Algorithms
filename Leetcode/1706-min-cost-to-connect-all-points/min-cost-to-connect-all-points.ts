// Prim's Algorithm O(n^2) as it is a dense graph, we won't use heap O(E log V) = O(n^2 log n) #unnecessary complexity
function minCostConnectPoints(points: [number, number][]): number {
  const n: number = points.length;
  let totalCost: number = 0;
  let edgesConnected: number = 0; // we abort after n-1 edges connected

  // this is basically our "formed" MST 
  const visited = new Uint8Array(n).fill(0);
  // minDist[i] = minimum cost to point i from any point in the formed MST(visited)
  const minDist = new Float64Array(n).fill(Infinity);
  minDist[0] = 0;

  while (edgesConnected < n) {
    let currNode = -1;
    let minWeight = Infinity;
    // could've used heap but this is cheaper in this case
    for (let i = 0; i < n; i++) {
      if (!visited[i] && minDist[i] < minWeight) {
        minWeight = minDist[i];
        currNode = i;
      }
    }

    // graph is connected as per the problem so no need but still for sake of safety
    if (currNode === -1) break;
    // update states ofc
    visited[currNode] = 1;
    totalCost += minWeight;
    edgesConnected++;

    // update the "reachability cost" for all neighbors because we just added "currNode", some other nodes might be easier to reach now than they were before.
    for (let nextNode = 0; nextNode < n; nextNode++) {
      if (visited[nextNode] === 1) continue;
      const dist = manhattanDistance(points[nextNode], points[currNode]);
      // if it's cheaper to reach nextNode via currNode, update it
      if (dist < minDist[nextNode]) {
        minDist[nextNode] = dist;
      }
    }
  }
  return totalCost;
};

function manhattanDistance(p1: [number, number], p2: [number, number]) {
  return Math.abs(p1[0] - p2[0]) + Math.abs(p1[1] - p2[1]);
}
