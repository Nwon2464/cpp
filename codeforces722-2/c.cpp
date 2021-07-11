#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>

using namespace std;

using ll = long long;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define f first
#define s second
#define pb push_back

// clang-format off
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T_vector>void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {if (start < 0) start = 0; if (end < 0) end = int(v.size()); for (int i = start; i < end; i++) cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');}
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << "(" << v.first << ":" << v.second << ")" << ","; os << "}"; return os; }


auto random_address = [] {char *p = new char; delete p;return uint64_t(p);};
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);
// clang-format on

const int maxn = 10;

int n;
int a[maxn][2];
vector<int> g[maxn];
long long f[maxn][2];

void dfs_solve(int v, int p) {
     for (int s : g[v])
          if (s != p) {
               dfs_solve(s, v);
               f[v][0] += max(f[s][0] + abs(a[s][0] - a[v][0]), f[s][1] + abs(a[s][1] - a[v][0]));
               f[v][1] += max(f[s][0] + abs(a[s][0] - a[v][1]), f[s][1] + abs(a[s][1] - a[v][1]));
          }
}

int main() {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);

     int ntest;
     cin >> ntest;
     while (ntest--) {
          cin >> n;
          for (int i = 0; i < n; ++i) {
               cin >> a[i][0] >> a[i][1];
          }

          for (int i = 0; i + 1 < n; ++i) {
               int u, v;
               cin >> u >> v;
               --u;
               --v;
               g[u].push_back(v);
               g[v].push_back(u);
          }

          dfs_solve(0, -1);
          cout << max(f[0][0], f[0][1]) << endl;

          for (int i = 0; i < n; ++i) {
               g[i].clear();
               f[i][0] = f[i][1] = 0;
          }
     }
     return 0;
}