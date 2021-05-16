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

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
// template<class Fun> class y_combinator_result {
//     Fun fun_;
// public:
//     template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
//     template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
// };
// template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
template<typename T_vector>void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) { if (start < 0) start = 0; if (end < 0) end = int(v.size()); for (int i = start; i < end; i++) cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void debug() { cerr << endl; }
template<typename Front, typename... End> void debug(Front H, End... T) { cerr << "debug=>" << H; debug(T...); }
auto random_address = [] {char *p = new char; delete p;return uint64_t(p);};

// clang-format on
const int sqq = sqrt(100001);
vector<ll> a(sqq), b(sqq);
vector<ll> c;
void factorization(ll n, bool flag) {
     for (ll d = 2; d * d <= n; d++) {
          while (n % d == 0) {
               if (!flag) {
                    a[d]++;
               } else {
                    b[d]++;
               }
               n /= d;
          }
     }
     if (n > 1) {
          a[n]++;
     }
     rep(i, 0, sqq) if (a[i] > 0) { c.push_back(a[i]); }
}
int main() {
     ios::sync_with_stdio(false);
#ifndef WON_DEBUG
     cin.tie(nullptr);
#endif
     vector<int> c(100001);
     vector<int> prefix;

     int tests;
     cin >> tests;
     int n, m;
     cin >> n >> m;
     ll xa = 1;
     rep(i, 0, n) {
          int x;
          cin >> x;
          xa = xa * x;
     }
     ll xb = 1, cnt = 0;

     rep(i, 0, m) {
          int y;
          cin >> y;
          xb = xb * y;
     }
     cout << xa << "\n";
     // vector<int> cc;
     factorization(xa, 0);
     factorization(xb, 1);
     vector<int> aa, bb;
     rep(i, 0, sqq) {
          if (a[i]) {
               int te = abs(a[i] - b[i]);
               te++;
               aa.push_back(te);
               a[i]--;
          }
     }
     rep(i, 0, sqq) {
          if (b[i]) {
               int te = abs(a[i] - b[i]);
               te++;
               bb.push_back(te);
               b[i]--;
          }
     }
     debug(aa, "A");
     debug(bb);
     // output_vector(a);

     // while (tests-- > 0)
     //     solve();
}