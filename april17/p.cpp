#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define f0rd(a, b) for (long long a = b; a >= 0; a--)
#define f1rd(a, b, c) for (long long a = b; a >= c; a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io                                \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);                   \
    }
#define mp make_pair
#define f first
#define s second
#define presum(p, a, n)             \
    {                               \
        p[0] = a[0];                \
        for (int i = 1; i < n; i++) \
            p[i] = a[i] + p[i - 1]; \
    }
#define all(v) v.begin(), v.end()
#define readgraph(list, edges)        \
    for (int i = 0; i < edges; i++) { \
        int a, b;                     \
        cin >> a >> b;                \
        a--;                          \
        b--;                          \
        list[a].pb(b);                \
        list[b].pb(a);                \
    }
#define ai(a, n)                      \
    for (int ele = 0; ele < n; ele++) \
        cin >> a[ele];
#define ain(a, lb, rb)                   \
    for (int ele = lb; ele <= rb; ele++) \
        cin >> a[ele];
#define ao(a, n)                            \
    {                                       \
        for (int ele = 0; ele < n; ele++) { \
            if (ele)                        \
                cout << " ";                \
            cout << a[ele];                 \
        }                                   \
        cout << '\n';                       \
    }
#define aout(a, lb, rb)                        \
    {                                          \
        for (int ele = lb; ele <= rb; ele++) { \
            if (ele > lb)                      \
                cout << " ";                   \
            cout << a[ele];                    \
        }                                      \
        cout << '\n';                          \
    }
typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

template <typename A, typename B>
ostream& operator<<(ostream& cout, pair<A, B> const& p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template <typename A>
ostream& operator<<(ostream& cout, vector<A> const& v)
{
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        if (i)
            cout << ", ";
        cout << v[i];
    }
    return cout << "]";
}
mt19937 rng(steady_clock::now().time_since_epoch().count());
/* usage - just do rng() */

const ll mod = 998244353;

ll madd(ll a, ll b)
{
    return (a + b) % mod;
}
ll msub(ll a, ll b)
{
    return (((a - b) % mod) + mod) % mod;
}
ll mmul(ll a, ll b)
{
    return ((a % mod) * (b % mod)) % mod;
}
ll mpow(ll base, ll exp)
{
    ll res = 1;
    while (exp) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        exp >>= 1;
        base = (base * base) % mod;
    }
    return res;
}
ll minv(ll base)
{
    return mpow(base, mod - 1);
}
ll mdiv(ll a, ll b)
{
    return mmul(a, minv(b));
}
ll gcd(ll x, ll y)
{
    if (x == 0)
        return y;
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

ll n, m, q, Q, T, k, l, r, x, y, z, g;
char mat[6][6];
int dist[3][6][6];
bool vis[6][6];
vpi nums[3];
const int dr[4] = { -1, 0, 1, 0 };
const int dc[4] = { 0, 1, 0, -1 };

int main()
{
    io;
    cin >> n >> m;
    f0r(i, n) ai(mat[i], m);

    ms(vis, 0);

    f0r(i, n)
    {
        f0r(j, m)
        {
            if (mat[i][j] == '1' || mat[i][j] == '2' || mat[i][j] == '3') {
                nums[mat[i][j] - '1'].pb(mp(i, j));
            }
        }
    }

    /* a 0-1 BFS */
    f0r(k, 3)
    {
        f0r(i, n) f0r(j, m) dist[k][i][j] = mod;
        deque<pair<pii, int>> dq;
        ms(vis, 0);
        for (pii i : nums[k]) {
            dq.pb(mp(i, 0));
        }

        while (!dq.empty()) {
            pair<pii, int> x = dq.front();
            // cout << k << " " << x << endl;
            dq.pop_front();

            if (vis[x.f.f][x.f.s])
                continue;
            vis[x.f.f][x.f.s] = 1;
            dist[k][x.f.f][x.f.s] = min(dist[k][x.f.f][x.f.s], x.s);

            f0r(i, 4)
            {
                int nr = x.f.f + dr[i], nc = x.f.s + dc[i];
                if (nr < 0 || nr > n - 1 || nc < 0 || nc > m - 1)
                    continue;
                if (vis[nr][nc])
                    continue;

                char h = mat[nr][nc];
                int v = h == '.';
                if (h == '#')
                    continue;

                if (v)
                    dq.pb(mp(mp(nr, nc), x.s + 1));
                else
                    dq.push_front(mp(mp(nr, nc), x.s));
            }
        }
        // f0r(i, n) {
        //   f0r(j, m) cout << dist[k][i][j] << " ";
        //   cout << endl;
        // }
    }

    ll mv = mod;
    f0r(i, n) f0r(j, m)
    {
        if (mat[i][j] != '#') {
            if (mat[i][j] == '.')
                mv = min(mv, (ll)dist[0][i][j] + dist[1][i][j] + dist[2][i][j] - 2);
            else
                mv = min(mv, (ll)dist[0][i][j] + dist[1][i][j] + dist[2][i][j]);
        }
    }
    cout << (mv == mod ? -1 : mv) << endl;
}
