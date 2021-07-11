#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>
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
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define sz(x) (int)(x).size()
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define s second
// clang-format off
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T_vector>void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {if (start < 0) start = 0; if (end < 0) end = int(v.size()); for (int i = start; i < end; i++) cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');}
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << "(" << v.first << ":" << v.second << ")" << ","; os << "}"; return os; }


auto random_address = [] {char *p = new char; delete p;return uint64_t(p);};
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);
// clang-format on
using u128 = __uint128_t;

const int nax = 10123;
char k[nax];
const int mod = 1e9 + 7;

void add_self(int &a, int b) {
     a += b;
     if (a >= mod) {
          a -= mod;
     }
}
struct UnionFind {
     vector<int> r;
     UnionFind(int N) { r = vector<int>(N, -1); }
     int root(int x) {  // rooting stage == collapsing find (find min and unite)
          if (r[x] < 0) return x;  // same as find set
          return r[x] = root(r[x]);
     }
     bool unite(int x, int y) {
          x = root(x);
          y = root(y);
          if (x == y) return false;
          if (r[x] > r[y]) swap(x, y);
          r[x] += r[y];
          r[y] = x;
          return true;
     }
     int size(int x) { return -r[root(x)]; }

     bool find_if_roots_are_same(int x, int y) { return root(x) == root(y); }
};

vector<int> g[200005];
bool used[200005];
vector<int> comp;

void dfs(int v) {
     used[v] = true;
     comp.push_back(v);
     for (int i = 0; i < (int)g[v].size(); ++i) {
          int to = g[v][i];
          if (!used[to]) dfs(to);
     }
}
int main() {
     // https://cses.fi/problemset/result/2474042/
     // how many connected components are there??
     // what are the disjoint components? print it if any
     // some of verticies are not given, so you have to
     // dfs that also.

     // always initialize with max edges (usually stands for m, not n)

     int n, m;
     cin >> n >> m;
     for (int i = 0; i < m; i++) {
          int x, y;
          cin >> x >> y;

          g[x].push_back(y);
          g[y].push_back(x);
     }
     int cnt = 0;
     vector<int> ans;
     for (int i = 1; i <= n; ++i) used[i] = false;
     for (int i = 1; i <= n; ++i)
          if (!used[i] && i != 0) {
               comp.clear();
               dfs(i);
               cnt++;  // to count how many disjoint componnets there are
               // cout << comp << endl;
               ans.push_back(comp[0]);  // to print each disjoint edges
          }

     cout << cnt - 1 << endl;
     for (int i = 0; i < sz(ans) - 1; i++) {
          cout << ans[i] << " " << ans[i + 1] << endl;
     }
     return 0;
}

// 2 - 5 - 6 - 8
// 1 - 4
