function solve(board: string[][]): void {
  const indices: Set<number[][]> = new Set();
  const DIRS: number[][] = [[-1, 0], [0, 1], [1, 0], [0, -1]]
  function dfs(r: number, c: number) {
    if (
      r < 0 ||
      r >= board.length ||
      c < 0 ||
      c >= board[0].length ||
      board[r][c] !== 'O' // no point to continue if it is not O (# or X)
    ) {
      return;
    }
    board[r][c] = '#'
    // traverse all direction
    for (const [dr, dc] of DIRS) {
      dfs(r + dr, c + dc);
    }
  }
  //traverse left and right edges
  for (let r = 0; r < board.length; r++) {
    if (board[r][0] === 'O') {
      dfs(r, 0);
    }
    if (board[r][board[0].length - 1] === 'O') {
      dfs(r, board[0].length - 1)
    }
  }
  // traver top and bottom edges
  for (let c = 0; c < board[0].length; c++) {
    if (board[0][c] === 'O') {
      dfs(0, c);
    }
    if (board[board.length - 1][c] === 'O') {
      dfs(board.length - 1, c)
    }
  }
  for (let r = 0; r < board.length; r++) {
    for (let c = 0; c < board[0].length; c++) {
      if (board[r][c] === 'O') { // if it is still O then it has no connection to edge
        board[r][c] = 'X';
      } else if (board[r][c] === '#') { // backtrack..? kinda.
        board[r][c] = 'O';
      }
    }
  }

};
