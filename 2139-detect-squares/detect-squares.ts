class DetectSquares {
  private points: Set<number[]> = new Set();// unique points
  private pointCount: Map<number, Map<number, number>> = new Map(); // map of x points to map of y points to their counts
  constructor() {
    this.points = new Set();
    this.pointCount = new Map();
  }

  add(point: [number, number]): void {
    const [x, y] = point;
    if (!this.pointCount.has(x)) {
      this.pointCount.set(x, new Map());
    }
    const yCountMap = this.pointCount.get(x)!;
    if (!yCountMap.has(y)) {
      yCountMap.set(y, 0);
      this.points.add([x, y]); // this is unique point
    }
    yCountMap.set(y, yCountMap.get(y)! + 1);// count increment
  }

  count(point: [number, number]): number {
    let count = 0;
    const [qx, qy] = point; // query point

    for (const [px, py] of this.points) {
      // difference of points 
      // if difference in x and y are same then it is diagonal
      const dx = Math.abs(px - qx);
      const dy = Math.abs(py - qy);
      // must be diagonal  (dx === dy) and must not be the same point
      if (dx == dy && dx !== 0) {
        // other corners (qx, py) and (px, qy) "axis aligned" to diagonal (px, py) must exist 
        // add the product of their counts to total count
        const countP2 = this.countPointOccurrences(qx, py);
        const countP3 = this.countPointOccurrences(px, py);
        const countP4 = this.countPointOccurrences(px, qy);
        count += countP2 * countP3 * countP4;
      }
    }
    return count;
  }
  countPointOccurrences(x: number, y: number): number {
    return this.pointCount.get(x)?.get(y) ?? 0;
  }
}

/**
 * Your DetectSquares object will be instantiated and called as such:
 * var obj = new DetectSquares()
 * obj.add(point)
 * var param_2 = obj.count(point)
 */