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
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define sz(x) (int)(x).size()
#define ms(arr, v) memset(arr, v, sizeof(arr))

// clang-format off
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T_vector>void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {if (start < 0) start = 0; if (end < 0) end = int(v.size()); for (int i = start; i < end; i++) cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');}
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << "(" << v.first << ":" << v.second << ")" << ","; os << "}"; return os; }


auto random_address = [] {char *p = new char; delete p;return uint64_t(p);};
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);
// clang-format on
// https://codeforces.com/contest/1527/problem/C
// still unsolved.
void solve() {
     int n;
     cin >> n;
     map<int, vector<int>> locs;
     for (int i = 0; i < n; i++) {
          int x;
          cin >> x;
          locs[x].push_back(i);
     }
     // using ll = int64_t;

     ll ans = 0;
     for (auto r : locs) {
          ll psum = 0;
          for (int x : r.second) {
               ans += psum * (n - x);
               psum += (x + 1);
          }
     }
     cout << ans << '\n';
}

int main() {
     ios_base::sync_with_stdio(false), cin.tie(nullptr);
     int T;
     cin >> T;
     while (T--)
          solve();
}
