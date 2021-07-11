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
vector<int> factorization;

void trial_division1(ll n) {
     for (ll d = 2; d * d <= n; d++) {
          while (n % d == 0) {
               factorization.push_back(d);
               n /= d;
          }
     }
     if (n > 1) {
          factorization.push_back(n);
     }
}
const int MOD = 1e9 + 7;
int print_mod(int a) { return (a % MOD + MOD) % MOD; }
int mul(int a, int b) { return (1LL * a * b) % MOD; }
int add(int a, int b) {
     int s = (a + b);
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

ll f(ll n) {
     return mul(mul(n, (n + 1)), inv(2));
}
int main() {
     int n;
     cin >> n;
     ll ans = 1;
     for (int i = 1; i <= n; i++) {

          ll r = n / (n / i);
          ans *= n / i * r * (r + 1) / 2 - i * (i - 1) / 2;
          i = r;
     }
     cout << ans << "\n";

     return 0;
}