/*
You are working on a large software project made up of n modules. Each module can have dependencies on other modules, meaning it cannot be built until all its dependencies are built.

You are given:

An integer n representing the number of modules, labeled 0 to n - 1.

A list dependencies, where each entry [a, b] means module a depends on module b (i.e., b must be built before a).

A list buildTime, where buildTime[i] is the time (in minutes) it takes to build module i.

Task:
Return the minimum total time required to build the entire project assuming:

Multiple modules can be built in parallel, as long as their dependencies are met.

Building starts at time 0.
Example:
n = 5
dependencies = [[1, 0], [2, 0], [3, 1], [3, 2], [4, 3]]
buildTime = [2, 3, 4, 5, 6]

Output:

17
*/

function BuildModules(dependencies: number[][], buildTime: number[], n: number): number {
  //build adj matrix and indegree
  let time: number = 0;
  const adj: Map<number, number[]> = new Map<number, number[]>();
  const indegree: number[] = Array(n).fill(0);
  for (const [dependency, prerequisite] of dependencies) {
    if (!adj.has(prerequisite)) adj.set(prerequisite, [])
    adj.get(prerequisite)?.push(dependency);
    console.log({ dependency, prerequisite })
    indegree[dependency]++;
  }

  const queue: number[] = [];
  for (let i = 0; i < n; i++) {
    if (indegree[i] === 0) {
      queue.push(i);
    }
  }
  console.log({ queue, indegree })
  while (queue.length > 0) {
    const curr: number = queue.shift()!;
    console.log({ curr, time })
    time += buildTime[curr];
    const neighbors: number[] = adj.get(curr) || [];
    for (const neighbor of neighbors) {
      indegree[neighbor]--;
      if (indegree[neighbor] === 0) {
        queue.push(neighbor);
      }
    }
  }
  console.log(time)
  return time
}

console.log(BuildModules([[1, 0], [2, 0], [3, 1], [3, 2], [4, 3]], [2, 3, 4, 5, 6], 5))
