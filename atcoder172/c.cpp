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
#define rep(i, n) for (int i = 0; i < (n); ++i)
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

const int mxN = 10;
int n, m;
ll k, a[mxN + 1], b[mxN + 1];
//https://atcoder.jp/contests/abc172/tasks/abc172_c
//very confusing for me. need to practice again
// it is about two pointer method

// input
// 3 4 240
// 60 90 120
// 80 150 80 150

// we use prefix sum
// 0 60 150 270        a
// 0 80 230 310 460    b

// i = 0 , j = last position of b which is m (b size)
// while a[i] + b[j] is greater than k, we decrement the j by 1
// 0 + 460 > 240 (k)
// 0 + 310 > 240
// 0 + 230 > 240 false, from here, we get max index i + j which is i = 0 , j = 2
// it means that a[0] and b[0] + b[1] + b[2] can safely pass a[0] + b[2] < k

// i = 1, j = 2 from last calculated index
// while(a[i] + b[j] > k)  is greater than k, decrement the j by 1 60 + 230 > 270
// 60 + 230 > 240 true
// 60 + 80 > 240 false, from here we find that we can safely say this is a[0]+a[1]  + b[0] + b[1] < k
// we get max here, but previous max index is greater.

// we keep going until i reach to n, then terminate.

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);

     cin >> n >> m >> k;
     for (int i = 0; i < n; ++i) {
          cin >> a[i + 1];
          a[i + 1] += a[i];
     }
     for (int i = 0; i < m; ++i) {
          cin >> b[i + 1];
          b[i + 1] += b[i];
     }
     int ans = 0;
     int ans2 = 0;
     for (int i = 0, j = m; i <= n; i++) {
          if (a[i] > k) break;
          while (a[i] + b[j] > k) {
               j--;
          }
          int x = a[i] + b[j];
          ans2 = max(ans2, x);
          ans = max(i + j, ans);
     }

     // ans2 is maximum value
     // ans is max index
     cout << ans2 << endl;
     cout << ans << endl;
}