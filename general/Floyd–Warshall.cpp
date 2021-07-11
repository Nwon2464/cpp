#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <climits>
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
#define endl "\n"

// clang-format off
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T_vector>void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {if (start < 0) start = 0; if (end < 0) end = int(v.size()); for (int i = start; i < end; i++) cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');}
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << "(" << v.first << ":" << v.second << ")" << ","; os << "}"; return os; }


auto random_address = [] {char *p = new char; delete p;return uint64_t(p);};
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);
// clang-format on

const int INF = 1001001001;
int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);

     // https://atcoder.jp/contests/abc208/tasks/abc208_d
     // Floyd-Warshall(negatives, positive)
     // N^3  (N<=500)
     // if only positive weights are given, disjkstra is more suitable

     int N, M;
     cin >> N >> M;

     vector<vector<int>> adj(N, vector<int>(N, INF));
     rep(i, 0, N) { adj[i][i] = 0; }
     for (int i = 0; i < M; i++) {
          int a, b, c;
          cin >> a >> b >> c;
          --a, --b;
          adj[a][b] = c;
     }

     ll answer = 0;
     rep(k, 0, N) rep(i, 0, N) rep(j, 0, N) {
          adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
          if (adj[i][j] != INF) answer += adj[i][j];
     }

     cout << answer << endl;
}
