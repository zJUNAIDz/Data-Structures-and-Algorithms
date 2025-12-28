type Point = [number, number];
function kClosest(points: number[][], k: number): number[][] {
  const pq = PriorityQueue<Point>((a, b) => calculateDistance(a, b), points);
  const res: Point[] = [];
  for (let i = 0; i < k; i++) {
    res.push(pq.dequeue())
  }
  return res;
};

function calculateDistance(p1: Point, p2: Point): number {
  const [x1, y1] = p1;
  const [x2, y2] = p2;
  //The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)^2 + (y1 - y2)^2).
  return ((Math.sqrt(x1 - x2) ** 2) + (Math.sqrt(y1 - y2) ** 2))
}

