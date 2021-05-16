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
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void debug() { cerr << endl; }
template<typename Head, typename... Tail> void debug(Head H, Tail... T) { cerr << "DEBUG => " << H; debug(T...); }
auto random_address = [] {char *p = new char; delete p;return uint64_t(p);};
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);
// clang-format on

void solve() {
     vector<int> c(1000001);
     for (int i = 2; i <= 1000000; i++) {
          int cnt = 0;

          if (!c[i]) {
               for (int j = i; j <= 1000000; j += i) {
                    cnt++;
                    cout << j << " ";
               }
               // for (int x = j; x % i == 0; x /= i)
               // {
          }
          c[i] = cnt;
          //}
     }
     vector<ll> sum(1000001);
     for (int i = 1; i <= 1000000; i++) sum[i] = sum[i - 1] + c[i];
     int t;

     cout << c[11];
     // cin >> t;
     // while (t--) {
     //      int a, b;
     //      scanf("%d%d", &a, &b);
     //      printf("%I64d\n", sum[a] - sum[b]);
     // }
}

int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);

     int tests;
     cin >> tests;
     while (tests-- > 0) solve();
}