function zeroPositions(matrix: number[][]): number[][] | null {
  let pos: number[][] = [];
  for (let i = 0; i < matrix.length; i++)
    for (let j = 0; j < matrix[0].length; j++)
      if (matrix[i][j] === 0)
        pos.push([i, j]);

  return pos.length ? pos : null;
}
function setZeroes(matrix: number[][]): void {
  const zeros: number[][] | null = zeroPositions(matrix);
  if (!zeros) return;
  //* iterate over zeroPosition pairs O(n^2)
  const row = matrix[0].length;
  const col = matrix.length;
  for (let i = 0; i < zeros.length; i++) {
    const m = zeros[i][0];
    const n = zeros[i][1];
    for (let j = 0; j < row; j++)
      matrix[m][j] = 0;
    for (let j = 0; j < col; j++)
      matrix[j][n] = 0;
  }
}
const mat: number[][] = [
  [1, 2, 0],
  [4, 0, 1],
];
console.log("matrix: ", mat);
setZeroes(mat);
console.log("zero positions:", zeroPositions(mat))
console.log("zerofied matrix:", mat);
