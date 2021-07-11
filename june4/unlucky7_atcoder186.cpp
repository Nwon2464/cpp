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

void solve() { }
int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     int n;
     cin >> n;
     set<int> st;
     // careful when decimal and octal,
     // it does not cover all the decimal(10-base) or the octal(8-base) when increasing by 10 or 8.
     // suppose 57,67,77 but what about 70 ? 70 is also unlucky number
     // suppose octal, you probably increase by 8 like 48,56,64, but what about 59 which is 73 in base 10
     // which is also unlucky number.

     auto convert = [&](int base, set<int> s) -> set<int> {
          for (int i = 1; i <= n; i++) {
               int x = i;
               while (x > 0) {
                    if (x % base == 7) s.insert(i);
                    x /= base;
               }
          }
          return st;
     };
     int base = 8;
     auto d = convert(base, st);
     base = 10;
     auto c = convert(base, d);

     cout << n - c.size();
     return 0;
}
