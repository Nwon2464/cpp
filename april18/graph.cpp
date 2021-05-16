#include <bits/stdc++.h>
using namespace std;
vector<int> E[7];
set<tuple<int, int, int>> evil;
int d[7][7];
tuple<int, int> p[7][7];
bool inqueue[7][7];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        E[x].push_back(y), E[y].push_back(x);
    }
    for (int i = 0, a, b, c; i < k; ++i)
        cin >> a >> b >> c, evil.insert({ a, b, c });
    memset(d, 31, sizeof d);
    queue<tuple<int, int>> Q;
    d[1][1] = 0;
    Q.push({ 1, 1 });
    while (!Q.empty()) {
        auto [x, y] = Q.front();
        Q.pop();
        inqueue[x][y] = 0;
        for (auto z : E[y]) {
            if (evil.count({ x, y, z }) == 0 and d[x][y] + 1 < d[y][z]) {
                d[y][z] = d[x][y] + 1, p[y][z] = { x, y };
                if (!inqueue[y][z])
                    Q.push({ y, z }), inqueue[y][z] = 1;
            }
        }
    }
    int l = 1e9;
    tuple<int, int> ans;
    for (int i = 1; i <= n; ++i)
        if (d[i][n] < l)
            l = d[i][n], ans = { i, n };
    if (l >= 1e7)
        cout << -1 << endl;
    else {
        cout << l << endl;
        vector<int> sol;
        for (auto x = ans; get<1>(x) != 1; x = p[get<0>(x)][get<1>(x)])
            sol.push_back(get<1>(x));
        sol.push_back(1);
        reverse(begin(sol), end(sol));
        for (auto x : sol)
            cout << x << ' ';
        cout << endl;
    }
    return 0;
}
