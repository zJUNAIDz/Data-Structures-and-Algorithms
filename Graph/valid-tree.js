function validTree(n, edges) {
  if (edges.length === 0) return true;
  if (edges.length !== n - 1) {
    return false
  }
  const adj = Array.from({ length: n + 1 }, () => [])
  for (const [u, v] of edges) {
    adj[u].push(v);
    adj[v].push(u);
  }

  const visited = new Set()
  const queue = [0]
  while (queue.length > 0) {
    const node = queue.pop();

    for (const nei of adj[node]) {
      if (!visited.has(nei)) {
        visited.add(nei)
        queue.push(nei)
      }
    }
  }
  return visited.size() === n;
}
