/**
 * @param {number[][]} grid
 * @return {number}
 */
var shortestPathBinaryMatrix = function (grid) {
  const H = grid.length;
  const W = grid[0].length;

  if (grid[0][0] == 1 || grid[H - 1][W - 1] == 1) return -1;

  const moves = [[1, 1], [0, 1], [1, 0], [-1, 1], [-1, 0], [1, -1], [0, -1], [-1, -1]];
  let q = [];

  q.push([0, 0]);
  grid[0][0] = 1;
  let i = 1;
  while (q.length != 0) {



    let [x, y] = q.shift();

    let dist = grid[x][y];
    console.log(grid, "------------", ++i);

    if (x == H - 1 && y == W - 1) return dist;
    for (let [a, b] of moves) {
      let dirX = a + x;
      let dirY = b + y;

      if (dirX >= 0 && dirY >= 0 && dirX < H && dirY < W && grid[dirX][dirY] == 0) {
        grid[dirX][dirY] = dist + 1;
        q.push([dirX, dirY]);
      }

    }
  }

  return -1;
  // return -1;


};
shortestPathBinaryMatrix([
  [0, 0, 0, 0, 1, 1, 0],
  [0, 1, 1, 0, 0, 0, 0],
  [0, 1, 0, 1, 1, 1, 1],
  [1, 0, 0, 1, 1, 0, 0],
  [0, 1, 0, 0, 0, 1, 0]]);
/*
  *
[[1,0,0]
 [1,1,0]
 [1,1,0]]
      *

 [0,0,0]
 [0,1,0]
 [0,0,0]
 */