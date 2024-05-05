function zeroPositions(matrix: number[][]): number[][] | null {
  let pos: number[][] = [];
  //* iterate over it
  for (let i = 0; i < matrix.length; i++) {
    for (let j = 0; j < matrix[0].length; j++) {
      if (matrix[i][j] === 0) pos.push([i, j]);
    }
  }
  return pos.length ? pos : null;
}

function setZeroes(matrix: number[][]): void {
  const zeros: number[][] | null = zeroPositions(matrix);
  if(!zeros) return;

  zeros.forEach((pos,index,arr)=>{
    let [i,j]= [pos[0],pos[1]];

  })
}

const mat: number[][] = [
  [1, 2, 3],
  [4, 0, 0],
];
console.log(mat, "\n");
console.log(zeroPositions(mat));
