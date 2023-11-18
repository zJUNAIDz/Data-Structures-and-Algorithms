interface Point {
  x: number;
  y: number;
}

function walk(
  maze: string[],
  wall: string,
  curr: Point,
  end: Point,
  visited: boolean[][]
): boolean {
  //* Base Cases
  //* Off the map
  if (
    curr.x < 0 ||
    curr.x >= maze[0].length ||
    curr.y < 0 ||
    curr.y >= maze.length
  )
    return false;

  //* On the wall
  if (maze[curr.y][curr.x] === wall) return false;
  //* At the end
  if (curr.x == end.x && curr.y == end.y) return true;
  //* Already Visited
  if (visited[curr.y][curr.x]) return false;
  return true;
}

function mazeSolver(
  maze: string[],
  wall: string,
  start: Point,
  end: Point
): Point[] {
  //* Dummy value to prevent error linting
  return [{ x: 1, y: 2 }] as Point[];
}
