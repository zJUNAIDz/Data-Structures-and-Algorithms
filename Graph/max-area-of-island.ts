function maxAreaOfIsland(grid: number[][]): number {
  let maxArea: number = 0;
  for (let row = 0; row < grid.length; row++) {
    for (let col = 0; col < grid[row].length; col++) {
      // dfs 
      if (grid[row][col] === 1) {
        const area: number = countArea(grid, row, col);
        maxArea = Math.max(maxArea, area);
      }
    }
  }
  return maxArea;
};

const DIRS: number[][] = [[-1, 0], [0, 1], [1, 0], [0, -1]] as const;
function countArea(grid: number[][], row: number, col: number): number {
  if (row < 0 || col < 0 || row >= grid.length || col >= grid[row].length || grid[row][col] === 0) {
    return 0;
  }
  //
  // let area: number = 1;
  grid[row][col] = 0; // mark as visited
  // for (const [dx, dy] of DIRS) {
  //   area += countArea(grid, row + dx, col + dy);
  // }
  // return area;
  return 1 +
    countArea(grid, row - 1, col) +
    countArea(grid, row, col + 1) +
    countArea(grid, row + 1, col) +
    countArea(grid, row, col - 1);
}
