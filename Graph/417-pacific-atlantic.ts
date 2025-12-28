function pacificAtlantic(heights: number[][]): number[][] {
  const rows = heights.length;
  const cols = heights[0].length;
  const pacific: boolean[][] = Array.from({ length: rows }, () => Array(cols).fill(false));
  const atlantic: boolean[][] = Array.from({ length: rows }, () => Array(cols).fill(false));

  // for pacific 

  for (let i = 0; i < rows; i++) {
    dfs(i, 0, pacific, -1, heights); // left endregion
    dfs(i, cols - 1, atlantic, -1, heights); // right endregion
  }
  for (let i = 0; i < cols; i++) {
    dfs(0, i, pacific, -1, heights); // top endregion
    dfs(rows - 1, i, atlantic, -1, heights); // bottom endregion
  }

  const result: [number, number][] = [];
  // take only common points
  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      if (pacific[i][j] && atlantic[i][j]) { // if it is true for both then water can fall to both oceans.
        result.push([i, j]);
      }
    }
  }
  return result;
};

const DIRS = [[-1, 0], [0, 1], [1, 0], [0, -1]];
function dfs(r: number, c: number, reachable: boolean[][], prev: number, heights: number[][]): void {
  if (
    r < 0 ||
    r >= heights.length ||
    c < 0 ||
    c >= heights[0].length ||
    reachable[r][c] === true ||
    heights[r][c] < prev
  ) {
    return;
  }

  reachable[r][c] = true;

  // traverse all four directions 
  for (const [dx, dy] of DIRS) {
    dfs(dx + r, dy + c, reachable, heights[r][c], heights);
  }
}
