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
const int mod = 1e9 + 7;

struct modint {
     ll n;
     modint()
         : n(0) { ; }
     modint(ll m)
         : n(m) {
          if (n >= mod)
               n %= mod;
          else if (n < 0)
               n = (n % mod + mod) % mod;
     }
     operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) {
     a.n += b.n;
     if (a.n >= mod) a.n -= mod;
     return a;
}
modint operator-=(modint& a, modint b) {
     a.n -= b.n;
     if (a.n < 0) a.n += mod;
     return a;
}
modint operator*=(modint& a, modint b) {
     a.n = ((ll)a.n * b.n) % mod;
     return a;
}
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) {
     if (n == 0) return modint(1);
     modint res = (a * a) ^ (n / 2);
     if (n % 2) res = res * a;
     return res;
}

ll inv(ll a, ll p) {
     return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint& a, modint b) {
     a = a / b;
     return a;
}
const int max_n = 1000005; //1 << 20;
modint fact[max_n], factinv[max_n];
void init_f() {
     fact[0] = modint(1);
     for (int i = 0; i < max_n - 1; i++) {
          fact[i + 1] = fact[i] * modint(i + 1);
     }
     factinv[max_n - 1] = modint(1) / fact[max_n - 1];
     for (int i = max_n - 2; i >= 0; i--) {
          factinv[i] = factinv[i + 1] * modint(i + 1);
     }
}
modint comb(int a, int b) {
     if (a < 0 || b < 0 || a < b) return 0;
     return fact[a] * factinv[b] * factinv[a - b];
}
modint combP(int a, int b) {
     if (a < 0 || b < 0 || a < b) return 0;
     return fact[a] * factinv[a - b];
}
int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     init_f();
     // cout << max_n << " ";
     rep(i, 0, 100) cout << fact[i] << " ";
     // int n, m;

     // cin >> n >> m;
     // modint ans = 0;
     // rep(i, 0, n + 1) {
     //      modint now = comb(n, i);
     //      now *= combP(m, n);
     //      now *= combP(m - i, n - i);
     //      if (i & 1) {
     //           now = -now;
     //      }
     //      ans += now;
     // }
     // cout << ans << endl;
     // int tests;
     // cin >> tests;
     // while (tests-- > 0)
     //      solve();
}
