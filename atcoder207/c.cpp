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

void solve() {
     // interval intersection
     // 1  2   A[0]
     //    2   2.5    A[1]
     //        2.5     4     A[2]

     // my first thought was max(1,2) in A[0] <= min (2,2.5) in A[1] and so on..
     // it turns out it isnt correct

     // correct way
     // max(1,2) in A[0],A[1] <= min ( 2,2.5) in A[0] , A[1]
     // first, calculate left interval, second calculate right interval
     // l r
     // 1 2
     // 7 8
     // 9 10
     // (1,7)  (2,8) compare
     // (1,9)  (2,10) compare
     // (7,9)  (8,10) compare

     int N;
     cin >> N;
     vector<pair<double, double>> A(N);
     for (int i = 0; i < N; i++) {
          double x, y;
          int t;
          cin >> t >> x >> y;
          if (t == 2) y -= 0.5;
          if (t == 3) x += 0.5;
          if (t == 4) y -= 0.5, x += 0.5;
          A[i] = {x, y};
     }
     int ans = 0;
     for (int i = 0; i < N; i++) {
          for (int j = i + 1; j < N; j++) {
               ans +=
                   max(A[i].first, A[j].first) <= min(A[i].second, A[j].second);
          }
     }
     // cout << A << endl;
     cout << ans << endl;
}

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     solve();
     // int tests;
     // cin >> tests;
     // while (tests-- > 0) solve();
}
