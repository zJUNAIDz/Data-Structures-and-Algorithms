function zeroPositions(matrix: number[][]): number[][] | null {
  let pos: number[][] = [];
  for (let i = 0; i < matrix.length; i++)
    for (let j = 0; j < matrix[0].length; j++)
      if (matrix[i][j] === 0) pos.push([i, j]);
  return pos.length ? pos : null;
}
function setZeroes(matrix: number[][]): void {
  const zeros: number[][] | null = zeroPositions(matrix);
  if (!zeros) return;
  //* iterate over zeroPosition pairs O(n^3)
  const matLen = matrix.length;
  for (let i = 0; i < zeros.length; i++) {
    const m = zeros[i][0];
    const n = zeros[i][1];
    for (let j = 0; j < matLen; j++)
      matrix[m][j] = matrix[j][n] = 0;
  }
}
const mat: number[][] = [
  [1, 2, 3],
  [4, 0, 0],
];
console.log(mat);
setZeroes(mat);
console.log(mat);
