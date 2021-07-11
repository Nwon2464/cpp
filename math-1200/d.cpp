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
void solve() {
     ll N, U, V;
     cin >> N >> U >> V;
     vector<int> A(N);
     for (auto &x : A) cin >> x;

     ll ans = INT_MAX;
     for (int i = 1; i < N; i++) {
          if (abs(A[i] - A[i - 1]) >= 2) ans = 0;
          if (A[i] == A[i - 1]) ans = min(ans, V + min(V, U));
          if (abs(A[i] - A[i - 1]) == 1) {
               ans = min(ans, min(U, V));
          }
     }
     cout << ans << endl;
}

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);

     // 2 2 0 2 1 0
     // 2 2 8 6 9 4
     //     |     |
     // | |   |
     //         |

     //     0     0
     // 2 2   2
     //         1
     // 2 1 3
     //
     int t;
     cin >> t;
     while (t--) {
          int N, M;
          cin >> N >> M;
          // vector<int> A(M);
          map<int, int> mp;
          rep(i, 0, N) {
               int x;
               cin >> x;
               mp[x % M]++;
               // A[x % M]++;
          }

          int ans = 0;
          for (auto x : mp) {
               int y = (M - x.first) % M;
               if (x.second + mp[y] >= 1 && x.first >= y) {
                    // cout << x.first << " " << y << endl;
                    // cout << x.second << " " << mp[y] << endl;
                    ans += max(abs(x.second - mp[y]), 1);
               }
          }
          cout << ans << endl;
          // for (int x = 0; x <= M / 2; x++) {
          //      int y = (M - x) % M;
          //      if (A[x] + A[y] >= 1) {
          //           cout << x << " " << y << endl;
          //           cout << A[x] << " " << A[y] << endl;
          //           ans += max(abs(A[x] - A[y]), 1);
          //      }
          // }
          // cout << A << endl;
          // cout << ans << endl;
     }

     // int tests;
     // cin >> tests;
     // while (tests-- > 0) solve();
}
