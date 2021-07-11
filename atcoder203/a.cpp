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

#define rep(i, n) for (int i = 0; i < (n); ++i)
// #define rep(i, a, b) for (int i = a; i < (b); ++i)
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

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);

     int n, k;
     cin >> n >> k;
     vector<vector<int>> a(n, vector<int>(n));
     // vector a(n, vector<int>(n));
     rep(i, n) rep(j, n) cin >> a[i][j];
     int L = k * k / 2 + 1;

     // cout << prefix;
     int wa = -1, ac = 11;
     while (wa + 1 < ac) {
          int wj = (wa + ac) / 2;
          bool ok = false;

          vector<vector<int>> prefix(n, vector<int>(n));
          rep(i, n) rep(j, n) prefix[i][j] = a[i][j] > wj ? 1 : 0;
          rep(i, n) rep(j, n) prefix[i][j] = prefix[i][j] + (j ? prefix[i][j - 1] : 0);
          rep(i, n) rep(j, n) prefix[i][j] = prefix[i][j] + (i ? prefix[i - 1][j] : 0);
          rep(i, n - k + 1) rep(j, n - k + 1) {
               int now = prefix[i + k - 1][j + k - 1] - (j ? prefix[i + k - 1][j - 1] : 0) - (i ? prefix[i - 1][j + k - 1] : 0) + (i && j ? prefix[i - 1][j - 1] : 0);
               if (now < L)
                    ok = true;
          }

          if (ok)
               ac = wj;
          else
               wa = wj;
     }
     cout << ac << endl;
     return 0;
}
