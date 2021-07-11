#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
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

// int main() {
//      ios::sync_with_stdio(0);
//      cin.tie(0);
//      // aj - j = ai - i;
//      // a[i] != A[j]
//      // int t;
//      // cin >> t;
//      // while (t--) {
//      int N;
//      cin >> N;
//      vector<int> A(N);
//      rep(i, 0, N) cin >> A[i];
//      vector<int> freq(N + 1);

//      sort(A.begin(), A.end());

//      for (int i = 0; i < N - 1; i++) {
//           if (A[i] == A[i + 1]) {
//                freq[i + 1] = freq[i] + 1;
//           }
//      }
//      // cout << freq << endl;
//      ll total = N * (N - 1) / 2;
//      for (int i = 0; i < sz(freq); i++) {
//           if (freq[i] > 0) {
//                total -= freq[i];
//           }
//      }
//      cout << total << endl;
//      return 0;
// }

const int mod = 1e9 + 7;

ll mod_pow(ll x, ll n, ll m = mod){if (n < 0) {ll res = mod_pow(x, -n, m); return mod_pow(res, m - 2, m);}if (abs(x) >= m)x %= m;if (x < 0)x += m;ll res = 1; while (n) { if (n & 1)res = res * x % m;x = x * x % m; n >>= 1;}return res;}
struct modint { ll n; modint(): n(0) { ; } modint(ll m) : n(m) {if (n >= mod) n %= mod; else if (n < 0) n = (n % mod + mod) % mod; } operator int(){return n;}};
bool operator==(modint a, modint b){return a.n == b.n; }
modint operator+=(modint& a, modint b){a.n += b.n;if (a.n >= mod) a.n -= mod;return a;}
modint operator-=(modint& a, modint b){a.n -= b.n;if (a.n < 0) a.n += mod;return a;}
modint operator*=(modint& a, modint b){a.n = ((ll)a.n * b.n) % mod;return a;}
modint operator+(modint a, modint b){return a += b;}
modint operator-(modint a, modint b){return a -= b;}
modint operator*(modint a, modint b){return a *= b;}
modint operator^(modint a, ll n) {if (n == 0) return modint(1);modint res = (a * a) ^ (n / 2);if (n % 2) res = res * a;return res;}
istream& operator>>(istream& is, const modint& a) { return is >> a.n; }
ostream& operator<<(ostream& os, const modint& a) { return os << a.n; }

ll inv(ll a, ll p) {return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);}
modint operator/(modint a, modint b){return a * modint(inv(b, mod));}
modint operator/=(modint& a, modint b){a = a / b;return a;}
const int max_n = 1000005; //1 << 20;
modint fact[max_n], factinv[max_n];
void init_f() {fact[0] = modint(1);for (int i = 0; i < max_n - 1; i++) {fact[i + 1] = fact[i] * modint(i + 1);}factinv[max_n - 1] = modint(1) / fact[max_n - 1]; for (int i = max_n - 2; i >= 0; i--) {factinv[i] = factinv[i + 1] * modint(i + 1);}}
modint comb(int a, int b) {if (a < 0 || b < 0 || a < b) return 0;return fact[a] * factinv[b] * factinv[a - b];}
modint combP(int a, int b) { if (a < 0 || b < 0 || a < b) return 0;return fact[a] * factinv[a - b];}
// clang-format on

vector<int> cal(int N) {
     if ((N & 1) == 1) {
          return {1, (N - 1) / 2, (N - 1) / 2};
     } else {
          // when n is even

          if (__builtin_popcount(N) == 1) {
               // when n is power of 2, or  if ((n & (n - 1)) == 0)
               return {N / 2, (N - (N / 2)) / 2, (N - (N / 2)) / 2};
          } else {
               int X = 1;
               while ((N - X) % 2 != 0) {
                    X *= 2;
               }
               // cout << X << endl;
               while (((N - X) / 2) % X != 0) {
                    X *= 2;
               }
               return {X, (N - X) / 2, (N - X) / 2};
          }
     }
}
void solve() {
     int N, K;
     cin >> N >> K;
     vector<int> A;

     while (K > 3) {
          A.push_back(1);
          N--;
          K--;
     }
     vector<int> ans = cal(N);
     ans.insert(ans.begin(), A.begin(), A.end());
     output_vector(ans);
     // when n is odd
     // 4
     // 2 1 1

     // 6
     // 2 2 2

     // 8
     // 4 2 2

     // 10
     // 2 4 4

     // 12
     // 4 4 4

     // 14
     // 2 6 6

     // 16
     // 8 4 4

     // 18
     // 2 8 8

     // 20
     // 4 8 8

     // 32
     // 16 8 8

     // 34
     // 2 16 16
     // 100
     // 2 49 49
     // 4 48 48
}

int main() {
     int t;
     cin >> t;
     while (t--) {
          solve();
     }
     return 0;
}
