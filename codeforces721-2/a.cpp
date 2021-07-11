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

void solve() {
     ll n;
     cin >> n;
     int s = n;
     while (s > 0) {
          if ((s & (s - 1)) == 0) {
               cout << s - 1 << "\n";
               break;
          }
          s = (s - 1) & n;
     }
}

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);

     // bit is power of 2
     // Given an integer n, find the maximum value of integer k such that the following condition holds:
     // n & (n−1) & (n−2) & (n−3) & ... (k) = 0

     // if n == 17, 17 & 16 = 10000, 16 & 15 = 0
     // where n is belong to ? 17 belongs to 2^4 to find maximum value that results in any number less than 17 and & operation equals to 0. it turns out 2^4 = 16 = 10000 (power of 2 has only 1 set bit)
     // 16(10000) & 15(1111) always gives 0, max possible ans is 15
     int t;
     cin >> t;
     while (t--) {
          int n;
          cin >> n;
          int x = 1;
          while ((x << 1) <= n) {
               x = x << 1;
          }
          cout << x - 1 << "\n";
     }
}
