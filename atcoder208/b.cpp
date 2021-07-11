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
#define endl "\n"

// clang-format off
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T_vector>void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {if (start < 0) start = 0; if (end < 0) end = int(v.size()); for (int i = start; i < end; i++) cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');}
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << "(" << v.first << ":" << v.second << ")" << ","; os << "}"; return os; }


auto random_address = [] {char *p = new char; delete p;return uint64_t(p);};
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);
// clang-format on
// 10000000
// 3628800
// 39916800
// 11!

vector<ll> fact(12);
void precal() {
     // precomputes all factorial [1!,2!,3!,....N]
     // O(N)  time
     fact[0] = 1;
     for (int i = 1; i < 12; i++) fact[i] = fact[i - 1] * i;
}
int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     precal();
     int P;
     cin >> P;
     int ans = 0;
     bool flag = 0;
     for (int i = 1; i < sz(fact); i++) {
          if (fact[i] == P) {
               ans = i;
               flag = 1;
          }
     }
     if (!flag) {
          vector<int> B;
          for (int i = 1; i < sz(fact); i++) {
               if (P > fact[i]) {
                    B.push_back(fact[i]);
               }
          }
          int need = 0;
          int W = P;
          int current = 0;

          for (int b = B.size() - 1; b >= 0; b--)
               while (W >= current + B[b]) {
                    current += B[b];
                    need++;
                    // freq[b]--;
               }
          ans = need;
     }
     cout << ans << endl;
}
