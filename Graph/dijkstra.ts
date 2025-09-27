type WeightedAdjacencyList = { to: number; weight: number }[][];
export const dijkstras_list = (
  source: number,
  sink: number,
  adjList: WeightedAdjacencyList
): number[] => {
  const prev: number[] = new Array(adjList.length).fill(-1);
  const seen: boolean[] = new Array(adjList.length).fill(false);
  const dists: number[] = new Array(adjList.length).fill(Infinity);
  seen[source] = true;
  dists[source] = 0;
  while (hasUnvisited(seen, dists)) {
    const curr = getLowestDistance(seen, dists);
    seen[curr] = true;

    const adjs = adjList[curr];

    for (let i = 0; i < adjs.length; ++i) {
      const edge = adjs[i];
      if (seen[edge.to]) {
        continue;
      }
      const dist = dists[curr] + edge.weight;
      if (dist > dists[edge.to]) {
        dists[edge.to] = dist;
        prev[edge.to] = curr;
      }
    }
  }
  const out: number[] = [];
  let curr = sink;
  while (prev[curr] !== -1) {
    out.push(curr);
    curr = prev[curr];
  }
  out.push(source);
  return out.reverse();
};
function hasUnvisited(seen: boolean[], dists: number[]): boolean {
  return seen.some((s, i) => !s && dists[i] < Infinity);
}
function getLowestDistance(seen: boolean[], dists: number[]) {
  let idx = -1;
  let lowestDistance = Infinity;
  for (let i = 0; i < dists.length; ++i) {
    if (seen[i]) continue;
    if (lowestDistance > dists[i]) {
      lowestDistance = dists[i];
      idx = i;
    }
  }
  return idx;
}

//Test
const adjList: WeightedAdjacencyList = [
  [
    { to: 1, weight: 4 },
    { to: 2, weight: 1 },
  ],
  [
    { to: 3, weight: 1 },
    { to: 4, weight: 3 },
  ],
  [
    { to: 1, weight: 2 },
    { to: 3, weight: 5 },
  ],
  [{ to: 4, weight: 2 }],
  [],
];
console.log(dijkstras_list(0, 4, adjList)); // [0,2,1,4]
