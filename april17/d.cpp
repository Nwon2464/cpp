#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
typedef long long ll;

string s;
ll n, m;
const int nax = 1e3 + 5;
ll dr[4] = { 0, 0, -1, 1 };
ll dc[4] = { 1, -1, 0, 0 };
bool mat[nax][nax];
bool vis[nax][nax];

bool valid(ll r, ll c)
{
    return r >= 0 && r < n && c >= 0 && c < m;
}

void solve()
{
    cin >> n >> m;
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    --a;
    --b;
    --c;
    --d;

    for (ll i = 0; i < n; i++) {
        cin >> s;
        for (ll j = 0; j < m; j++) {
            mat[i][j] = (s[j] == '.');
        }
    }

    deque<pair<pair<ll, ll>, ll>> q;

    q.push_front(make_pair(make_pair(a, b), 0));

    while (!q.empty()) {
        pair<pair<ll, ll>, ll> x = q.front();
        q.pop_front();

        pair<ll, ll> pos = x.f;

        if (vis[pos.f][pos.s])
            continue;
        vis[pos.f][pos.s] = 1;

        if (pos.f == c && pos.s == d) {
            cout << x.s << '\n';
            return;
        }

        for (ll d = 0; d < 4; d++) {
            ll nr = pos.f + dr[d];
            ll nc = pos.s + dc[d];
            // valid ==>   0 <= x <h && 0<= y < w
            // mat ==>   .

            if (valid(nr, nc) && mat[nr][nc] && !vis[nr][nc]) {
                q.push_front(make_pair(make_pair(nr, nc), x.s));
            }
        }

        for (ll dr = -2; dr <= 2; dr++) {
            for (ll dc = -2; dc <= 2; dc++) {
                ll nr = pos.f + dr;
                ll nc = pos.s + dc;

                if (valid(nr, nc) && mat[nr][nc] && !vis[nr][nc]) {
                    q.push_back(make_pair(make_pair(nr, nc), x.s + 1));
                }
            }
        }
    }

    cout << -1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
