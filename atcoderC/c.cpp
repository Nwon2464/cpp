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
using u128 = __uint128_t;

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
bool isPrime(ll n) {
     if (n == 1) return false;

     if (n == 2 || n == 3) return true;

     if (n % 2 == 0 || n % 3 == 0) return false;

     for (ll i = 5; i * i <= n; i = i + 6) {
          if (n % i == 0 || n % (i + 2) == 0) return false;
     }

     return true;
}
ll gcd(ll a, ll b) {
     return (b == 0 ? a : gcd(b, a % b));
}

int get(int x) {
     trial_division1(x);

     map<ll, int> mp;
     int sz = factorization.size();
     for (int i = 0; i < sz; i++) {
          mp[factorization[i]]++;
     }
     int ans = 0;
     // cout << factorization;
     for (auto x : mp) {
          int v = x.second;
          // cout << x.first << "^" << x.second << " ";
          int b = 1;
          while (b <= v) {
               v -= b;
               b++;
               ans++;
          }
     }
     return ans;
}
int main() {
     ll n, n2, n3;
     cin >> n >> n2 >> n3;
     // if (isPrime(n)) return cout << 1, 0;

     map<ll, int> mp;
     int sz = factorization.size();
     for (int i = 0; i < sz; i++) {
          mp[factorization[i]]++;
     }
     int ans = 0;
     // cout << factorization;
     for (auto x : mp) {
          int v = x.second;
          // cout << x.first << "^" << x.second << " ";
          int b = 1;
          while (b <= v) {
               v -= b;
               b++;
               ans++;
          }
     }

     cout << ans << "\n";
}
