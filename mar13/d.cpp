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

#include <set>
using namespace std;
int numIslands(vector<vector<char>>& grid)
{
    int cnt = 0;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n));
    vector<pair<int, int>> directions { { 1, 0 }, { -1, 0 }, { 0, -1 }, { 0, 1 } };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1' && !visited[i][j]) {
                ++cnt;

                queue<pair<int, int>> q;
                q.push({ i, j });
                visited[i][j] = true;
                while (!q.empty()) {
                    pair<int, int> p = q.front();
                    q.pop();
                    for (pair<int, int> dir : directions) {
                        int x = dir.first + p.first;
                        int y = dir.second + p.second;
                        if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == '1' && !visited[x][y]) {
                            q.push({ x, y });
                            visited[x][y] = true;
                        }
                    }
                }
            }
        }
    }
    return cnt;
}

int main()
{
    vector<vector<char>> grid { { "1", "1", "1", "1", "0" },
        { "1", "1", "0", "1", "0" },
        { "1", "1", "0", "0", "0" },
        { "0", "0", "0", "0", "0" } };
    int t = numIslands(grid);
    cout << t;
}
