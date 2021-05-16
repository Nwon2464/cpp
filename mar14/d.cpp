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

class Solution {
    const int INF = 1e9 + 5;
    vector<vector<int>> find_next(const vector<int>& colors)
    {
        cout << colors;
        const int n = colors.size();
        vector<vector<int>> nxt(n, vector<int>(4));
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                nxt[i] = { 0, INF, INF, INF };

            } else {
                for (int c = 1; c <= 3; ++c) {
                    nxt[i][c] = nxt[i + 1][c] + 1;
                }
            }
            nxt[i][colors[i]] = 0;
        }
        return nxt;
    }

public:
    vector<int> shortestDistanceColor(vector<int>& colors,
        vector<vector<int>>& queries)
    {
        vector<vector<int>> nxt = find_next(colors);
        reverse(colors.begin(), colors.end());
        vector<vector<int>> prv = find_next(colors);
        vector<int> answer;
        const int n = colors.size();
        for (vector<int> query : queries) {
            int i = query[0];
            int c = query[1];
            int dist = min(nxt[i][c], prv[n - 1 - i][c]);
            if (dist >= INF) {
                answer.push_back(-1);
            } else {
                answer.push_back(dist);
            }
        }
        return answer;
    }
};
int main()
{
    vector<int> colors { 1, 1, 2, 1, 3, 2, 2, 3, 3 };
    vector<vector<int>> queries { { 1, 3 }, { 2, 2 }, { 6, 1 } };

    Solution s;
    vector<int> a;

    a = s.shortestDistanceColor(colors, queries);
    for (int i = 0; i < (int)a.size(); i++) {
        cout << a[i] << "\n";
    }
    // shortestDistanceColor(colors, queries);

    return 0;
}
