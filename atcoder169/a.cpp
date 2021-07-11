#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iomanip>
#include <ios>
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
using u128 = __uint128_t;
const int mod = 1e9 + 7;
const int MOD = 1e9 + 7;
// ll multiplyFactors(ll n, ll numFactor) {

//      // Calculate product of factors
//      ll product = binpower(n, numFactor / 2);

//      // If numFactor is odd return
//      // power(n, numFactor/2) * sqrt(n)
//      if (numFactor & 1)
//           product = (product * (int)sqrt(n)) % mod;

//      return product;
// }

ll sumFactors(ll n) {
     ll res = 1;
     for (int i = 2; i * i <= n; i++) {
          ll sum = 1;
          ll term = 1;
          while (n % i == 0) {
               n = n / i;
               term = term * i;
               sum += term;
          }
          res = res * sum;
     }
     if (n >= 2) {
          res = res * (n + 1);
     }
     return res;
}
int mul(int a, int b) { return (1LL * a * b) % MOD; }
int add(int a, int b) {
     int s = (a + b);
     if (s >= MOD) s -= MOD;
     return s;
}
int sub(int a, int b) {
     int s = (a + MOD - b);
     if (s >= MOD) s -= MOD;
     return s;
}
int binpow(int a, ll deg) {
     if (deg == 0) return 1;
     if (deg % 2 == 1) return mul(a, binpow(a, deg - 1));
     int t = binpow(a, deg / 2);
     return mul(t, t);
}
int inv(int n) { return binpow(n, MOD - 2); }

ll binpower(ll a, ll b) {
     a %= mod;
     ll res = 1;
     while (b > 0) {
          if (b & 1)
               res = res * a % mod;
          a = a * a % mod;
          b >>= 1;
     }
     return res;
}

int main() {

     int n;
     cin >> n;
     vector<ll> p, k;
     rep(i, 0, n) {
          int x, y;
          cin >> x >> y;
          p.emplace_back(x), k.emplace_back(y);
     }
     ll div_cnt = 1, div_sum = 1, div_prod = 1, div_cnt2 = 1;
     for (int i = 0; i < n; i++) {
          div_cnt = div_cnt * (k[i] + 1) % MOD;
          // div_sum = div_sum * (binpow(p[i], k[i] + 1) - 1) % MOD * binpow(p[i] - 1, MOD - 2) % MOD;

          // div_prod = binpower(div_prod, k[i] + 1) * binpower(binpower(p[i], (k[i] * (k[i] + 1) / 2)), div_cnt2) % MOD;
          // div_cnt2 = div_cnt2 * (k[i] + 1) % (MOD - 1);

          div_sum = mul(div_sum, mul(binpow(p[i], k[i] + 1) - 1, inv(p[i] - 1)));
          div_prod = mul(binpower(div_prod, k[i] + 1), binpower(binpower(p[i], (k[i] * (k[i] + 1) / 2)), div_cnt2));
          div_cnt2 = div_cnt2 * (k[i] + 1) % (MOD - 1);
     }
     cout << div_cnt << ' ' << div_sum << ' ' << div_prod;

     return 0;
}
