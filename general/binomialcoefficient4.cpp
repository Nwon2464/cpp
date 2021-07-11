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

ll pascal(ll total, ll objects) {
     ll maxn = total; // declare max n in nCr
     ll c[maxn + 1][maxn + 1];
     c[0][0] = 1;
     for (ll n = 1; n <= maxn; ++n) {
          c[n][0] = c[n][n] = 1;
          for (ll k = 1; k < n; ++k)
               c[n][k] = c[n - 1][k - 1] + c[n - 1][k];
     }
     return c[total][objects];
}
ll C(ll n, ll k) { // up until 8*10^18 long long
     long double res = 1;
     for (ll i = 1; i <= k; ++i)
          res = res * (n - k + i) / i;
     return (ll)(res + 0.01);
}

using u128 = __uint128_t;
ll C2(ll n, ll r) { // up until ll range
     // int n, r;
     // cin >> n >> r;
     u128 ans = 1;
     for (int i = 1; i <= r; ++i) {
          ans *= n - i + 1;
          ans /= i;
     }

     return ll(ans);
}
int main() {
     //https://cp-algorithms.com/combinatorics/binomial-coefficients.html
     // three ways to to calculate binomial coefficient without using MOD and without overflow
     // first method
     // simple implementation using long double
     // second method
     // pascal triangle O(n^2) quite slow. no need to worry about overflow
     // each time, need O(n^2)

     // pascal trainagle, example. 5C2 => creates 2d array size a[5+1][5+1]

     // in index 5 row, it generates all the possible values of 5Cr until 5
     // like 5C0 5C1 5C2 5C3 5C4 5C5
     int n, r;
     cin >> n >> r;

     // n C r
     cout << C(n, r) << endl;
     cout << C2(n, r) << endl;
     cout << pascal(n, r) << endl; // getting (n-1)C(11)
     return 0;
}

// third method  5C2 => 5 * 4 / 2 * 1 similiar with method1
// using u128 = __uint128_t;
// int main() {
//      int n, r;
//      cin >> n >> r;
//      u128 ans = 1;
//      for (int i = 1; i <= r; ++i) {
//           ans *= n - i + 1;
//           ans /= i;
//      }

//      cout << ll(ans) << endl;
//      return 0;
// }
