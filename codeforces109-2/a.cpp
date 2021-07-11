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

// int gcd(int a, int b) {
//      return (b == 0 ? a : gcd(b, a % b));
// }
// int main() {
//      int t;
//      cin >> t;
//      while (t--) {
//           int n;
//           cin >> n;
//           vector<int> a(n), b;
//           rep(i, 0, n) cin >> a[i];
//           rep(i, 0, n) {
//                if ((a[i] & 1) == 0)
//                     b.push_back(a[i]);
//           }
//           rep(i, 0, n) {
//                if (a[i] & 1)
//                     b.push_back(a[i]);
//           }
//           int ans = 0;
//           rep(i, 0, n) rep(j, i + 1, n) {
//                if (gcd(b[i], 2 * b[j]) > 1) {
//                     ans++;
//                }
//           }
//           cout << ans << endl;
//      }
//      return 0;
// }

void run_case() {
     string S;
     cin >> S;
     int N = int(S.size());
     vector<int> prefix_count[2][2];
     for (int x = 0; x < 2; x++)
          for (int p = 0; p < 2; p++) {
               prefix_count[x][p].assign(N + 1, 0);

               for (int i = 0; i < N; i++)
                    prefix_count[x][p][i + 1] =
                        prefix_count[x][p][i] + (i % 2 == p && S[i] - '0' == x);
          }

     auto exists = [&](int start, int end, int x, int p) -> bool {
          return prefix_count[x][p][end] - prefix_count[x][p][start] > 0;
     };

     auto beautiful = [&](int start, int end) -> bool {
          for (int x = 0; x < 2; x++)
               if (exists(start, end, x, 0) && exists(start, end, x, 1))
                    return false;

          for (int p = 0; p < 2; p++)
               if (exists(start, end, 0, p) && exists(start, end, 1, p))
                    return false;

          return true;
     };

     int64_t total = 0;

     for (int start = 0; start < N; start++) {
          int low = start, high = N;

          while (low < high) {
               int mid = low + (high - low + 1) / 2;

               if (beautiful(start, mid))
                    low = mid;
               else
                    high = mid - 1;
          }

          total += low - start;
     }

     cout << total << '\n';
}
void solve() {
     int lst[2];
     lst[0] = -1;
     lst[1] = -1;
     string S;
     cin >> S;
     int N = sz(S);
     ll ans = 0;
     rep(i, 0, N) {
          if (S[i] != '?') {
               int p = '0' + i - S[i] + 2;
               p %= 2;
               lst[p] = i;
          }
          ans += i - min(lst[0], lst[1]);
     }
     cout << ans << endl;
}
int main() {
     // vector<int> a = { 5, 4, 3, 2, 1 };
     // run_case();
     // solve();

     return 0;
}
