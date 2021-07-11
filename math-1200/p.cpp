#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <climits>
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
#define rep(i, b) for (int i = 0; i < (b); ++i)
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
int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     int tc;
     cin >> tc;
     while (tc--) {
          int n;
          cin >> n;
          int t = n;
          n = 2 * n;
          vector<int> A(n);
          rep(i, n) cin >> A[i];

          // sort(A.begin(), A.end(), [&](int x, int y) { return x % 2 < y % 2;
          // });
          int cnt = 0;
          for (int i = 0; i < n; i += 2) {
               if ((A[i] + A[i + 1]) % 2 == 1) {
                    cnt++;
               }
          }
          // cout << cnt << endl;
          cout << (cnt == t ? "Yes" : "No") << endl;
     }
     return 0;
}

// -6 1 -4
// 1 4 6
//