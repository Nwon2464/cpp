// Debug, type gdb filename  not filename.out or cpp
// b - main b stands for break
// r - run
// l - Stands for list that will debug for
// f - Defines where the debugger right now
// n - Step over (Does't step into functions)
// s - Step into
// p - Print variable
// bt- Print a stack trace
// c - Continues running the program until the next breakpoint or error
// r - Runs the program until a breakpoint or error

#include <bits/stdc++.h>

using namespace std;

bool checkPalindromePermutation(const string s) {
  vector<int> ascii(26, 0);
  for (int c : s) {
    if ('a' <= c && c <= 'z') {
      ascii[c - 'a']++;
    } else if ('A' <= c && c <= 'Z') {
      ascii[c - 'A']++;
    }
  }
  int cnt = 0;
  for (int i = 0; i < ascii.size(); i++) {
    if (ascii[i] % 2 == 1) {
      cnt++;
    }
  }
  if (cnt <= 1) {
    return true;
  } else {
    return false;
  }
}

int main() {
  // string s = "Rats live on no evil star";
  // if (checkPalindromePermutation(s)) {
  //   cout << "YES";
  // } else {
  //   cout << "No";
  // }

  string sieveChars(50, 'P');
  sieveChars.replace(0, 2, "NN");
  for (int i = 2; i <= (sieveChars.size() / 2) - 1; i++) {
    for (int factor = 2; factor * i < sieveChars.size(); factor++) {
      sieveChars[factor * i] = 'N';
    }
  }

  return 0;
}

class Solution {
 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    const int H = grid.size();
    const int W = grid[0].size();
    if (grid[0][0] == 1 || grid[H - 1][W - 1] == 1) return -1;

    vector<pair<int, int>> moves{{1, 1},  {0, 1},  {1, 0},  {-1, 1},
                                 {-1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    queue<pair<int, int>> q;
    int cnt = 1;

    for (int row = 0; row < H; ++row) {
      for (int col = 0; col < W; ++col) {
        if (visited[row][col] == false) {
          q.push({row, col});
          visited[row][col] = true;
          while (!q.empty()) {
            int size = q.size();
            int mxX = 0;
            int mxY = 0;

            pair<int, int> p = q.front();
            q.pop();
            for (pair<int, int> dir : moves) {
              int dirX = dir.first + p.first;
              int dirY = dir.second + p.second;

              if (dirX >= 0 && dirY >= 0 && dirX < H && dirY < W &&
                  !visited[dirX][dirY] && grid[dirX][dirY] == 0) {
                mxX = max(mxX, dirX);
                mxY = max(mxY, dirY);
                visited[dirX][dirY] = true;
                q.push({dirX, dirY});
              }

              /*[[0,0,1,0],
               [1,0,1,0],
               [1,1,0,1],
               [0,0,0,0]]*/
            }
            cout << mxX << " " << mxY << endl;

            if (mxX == 0 && mxY == 0) {
              continue;
            } else {
              if (grid[mxX][mxY] == 0 && visited[mxX][mxY] == true) {
                cnt++;
              }
            }
          }
        }
      }
    }
    return cnt;
  }
};
