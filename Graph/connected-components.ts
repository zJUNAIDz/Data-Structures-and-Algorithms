function countComponents(n: number, edges: number[][]) {
  let res: number = 0;
  const visited: Set<number> = new Set();
  const adj: number[][] = Array.from({ length: n }, () => []);
  for (let [u, v] of edges) {
    adj[u].push(v);
    adj[v].push(u);
  }
  for (let i = 0; i < n; i++) {
    if (!visited.has(i)) {
      visited.add(i)
      res++;
      dfs(i);
    }
  }
  function dfs(node: number) {
    for (const nei of adj[node]) {
      if (!visited.has(nei)) {
        visited.add(nei);
        dfs(nei)
      }
    }
  }
  return res;
}
