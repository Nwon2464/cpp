/**
 * @param {number[][]} grid
 * @return {number}
 */
var shortestPathBinaryMatrix = function (grid) {
  const H = grid.length;
  const W = grid[0].length;

  if (grid[0][0] == 1 || grid[H - 1][W - 1] == 1) return -1;
  let q = []
  const moves = [[1, 0], [0, 1]];
  let dp = new Array(H).fill(0).map(e => new Array(W).fill(0))
  dp[0][0] = 1;
  for (let row = 0; row < H; row++) {
    for (let col = 0; col < W; col++) {

      for (let [x, y] of moves) {
        let r2 = x + row;
        let c2 = y + col;
        if (r2 < H && c2 < W && grid[r2][c2] == ".") {
          dp[r2][c2] += dp[row][col];

          // grid[a][b] == "#";
        }

        //[0,1], [1,0]
        //[0,2],[1,1]

      }
    }
  }

  console.log(dp);

};

shortestPathBinaryMatrix([[".", ".", ".", "#"], [".", "#", ".", "."], [".", ".", ".", "."]]);

