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
const char el = '\n';

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

     int n;
     cin >> n;
     vector<int> h(n);

     for (int i = 0; i < n; i++) {
          cin >> h[i];
     }
     sort(h.begin(), h.end());

     if (n == 2) {
          cout << h[0] << " " << h[1] << "\n";

     } else {
          int mn = 1000000000;
          int pos = 0;
          for (int i = 0; i < n - 1; i++) {
               if (abs(h[i] - h[i + 1]) < mn) {
                    pos = i + 1;
                    mn = abs(h[i] - h[i + 1]);
               }
          }
          rep(i, pos, n) {
               cout << h[i] << " ";
          }
          rep(i, 0, pos) {
               cout << h[i] << " ";
          }
          cout << el;
     }
}
// 1 2 3 4 6 12
//12 - 3 = 9
//9 - 3 =  6
//    6 - 3 = 3
//
int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);

     int tests;
     cin >> tests;
     while (tests-- > 0)
          solve();
}
