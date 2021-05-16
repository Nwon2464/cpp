
#include <bits/stdc++.h>

// leetcode numberofIslands problem
using namespace std;

class Solution {
    void bfs(vector<pair<int, int>> directions, int i, int j, vector<vector<char>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        for (pair<int, int> dir : directions) {
            int x = dir.first + i;
            int y = dir.second + j;
            if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == '1') {
                grid[x][y] = '0';
                bfs(directions, x, y, grid);
            }
        }
    }

public:
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
        cout << cnt;
        return cnt;
    }
};
int main()
{

    vector<vector<char>> grid { { '1', '1', '1', '1', '0' }, { '1', '1', '0', '1', '0' }, { '1', '1', '0', '0', '0' }, { '0', '0', '0', '0', '0' } };

    Solution T;
    int ans = T.numIslands(grid);

    cout << ans << endl;
    return 0;
}
