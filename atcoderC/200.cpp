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
#include <ostream>
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
const char el = '\n';

// clang-format off
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T_vector>void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {if (start < 0) start = 0; if (end < 0) end = int(v.size()); for (int i = start; i < end; i++) cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');}
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << "(" << v.first << ":" << v.second << ")" << ","; os << "}"; return os; }


auto random_address = [] {char *p = new char; delete p;return uint64_t(p);};
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);
// clang-format on
ll max_pair(int N) {
     ll a = 0, b = 0;
     ll possible = 0;
     for (int i = 2; i <= N; i++) {
          a += b;
          b += 1;
          possible += b;
     }
     return possible;
}
ll max_pair2(ll N) { return (N * (N - 1)) / 2; }

// 8 4 2 1
// 12 =      1 1 0 0    1
//             1 1 0    2
//               1 1    3
//                 1    4
void output(int s) {
     vector<int> a;
     int i = 1;

     while (s) {
          if (s & 1) a.push_back(i);
          ++i;
          s >>= 1;
     }
     cout << sz(a) << " ";
     output_vector(a);
}
void solve2() {
     int n;
     cin >> n;
     vector<int> A(n);
     rep(i, 0, n) cin >> A[i];
     n = min(n, 8);
     // pigeonhole principle
     // if n items are put into m containers, with n > m, then
     // at least one container must contain more than one item.
     // in this case,
     // objects 255 out of 200, there are always AT LEAST more than
     // one sequence.

     // since constraint of N is N <= 200
     // we can conclude N should be at least 8 (2^8 = 255 > 200) to
     // qualify the pigeonhole principle.
     // if N == 7, 2^7 < 200 not valid

     vector<int> C(200);
     for (ll msk = 1; msk < (1 << n); msk++) {
          ll x = 0;
          for (ll i = 0; i < n; i++) {
               if (msk & (1 << i)) {
                    x = (x + A[i]) % 200;
               }
          }
          if (C[x] == 0) {
               C[x] = msk;
          } else {
               cout << "YES" << endl;
               cout << msk << endl;
               cout << C[x] << endl;
               output(msk);
               output(C[x]);
               return;
          }
     }
     cout << "No" << endl;
}
int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     solve2();
     // int tests;
     // cin >> tests;
     // while (tests-- > 0)
     // solve();
}
