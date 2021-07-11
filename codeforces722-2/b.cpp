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
#include <string>
#include <utility>
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
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);mt19937_64 rng(SEED);



int MOD = 1e9 + 7;

int mul(int a, int b){return (1LL * a * b) % MOD;}
int add(int a, int b){int s = (a + b);if (s >= MOD)s -= MOD; return s;}
int sub(int a, int b){int s = (a + MOD - b);if (s >= MOD)s -= MOD;return s;}
int binpow(int a, ll deg){if (deg == 0) return 1;if (deg % 2 == 1) return mul(a, binpow(a, deg - 1)); int t = binpow(a, deg / 2); return mul(t, t);}
int inv(int n){return binpow(n, MOD - 2);}

const int N = 1e6 + 7;
ll fact[N];

void precal_factmod() {
     fact[0] = 1;
     for (ll i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
}
ll nCr(ll n, ll r) { if (r < 0 || r > n) return 0;return mul(fact[n], inv(mul(fact[r], fact[n - r]))); }
ll nPr(ll n, ll r) { return mul(fact[n], inv(fact[n - r])); }
// clang-format on
int print_mod(int a) { return (a % MOD + MOD) % MOD; }

void solve() {
     ll n, m;
     cin >> n >> m;
     ll ans = 0;
     for (ll i = 0; i < n + 1; i++) {
          ll now = nCr(n, i);
          // now *= nPr(m, n);
          // now *= nPr(m - i, n - i);
          now = mul(now, nPr(m, n));
          now = mul(now, nPr(m - i, n - i));
          if (i & 1) {
               now = -now;
               if (now < 0) now += MOD;
               // now = -now;
               // }
          }
          ans = add(ans, now);
     }
     cout << ans << endl;
}
int main() {

     precal_factmod();
     solve();
     return 0;
}
