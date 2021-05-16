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
#define rip(i, a, b) for (int i = a; i < (b); ++i)
#define ripp(i, a, b) for (int i = a; i <= (b); ++i)
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

using u64 = uint64_t;
using u128 = __uint128_t;

ll r, k;

void solve() {
     int n;
     cin >> n;
     vector<ll> p;
     // if r= 20,
     // and prime number is not given, instead natural number is given n = 20,
     // you need to find and
     // count the number of integers in the interval [1;r] that are relatively
     // prime to n
     //(their greatest common divisor is 1).
     cin >> r >> k;
     for (int i = 0; i < k; i++) {
          ll x;
          cin >> x;
          p.push_back(x);
     }
     ll sum = 0;
     for (ll msk = 1; msk < (1 << p.size()); ++msk) {
          double mult =
              1;  // double in used  to prevent from multiplying overflow
          ll bits = 0;
          for (ll i = 0; i < (ll)p.size(); ++i)
               if (msk & (1 << i)) {
                    ++bits;
                    mult *= p[i];  // ------------------
               }  // when you mult *= p[i] since double in used, prevent from
                  // overflow
          // when mult *= p[i] with double , it give me scientific value i,e
          // x.xxxxxxe+32
          // 24929660627620033 * 16706748220911473 ==> overflow when used ll
          // mult = 1

          ll cur = r / (ll)mult;
          // typecasting needed to get 0 for ll cur
          // i.e) if you dont typecasting  r / x.xxxxxxxx+30 =>
          // x.xxxxxxxxxx+xx if you typecast, r / (ll)mult = 0,
          // bc demoniator is always greater in this case.

          if (bits % 2 == 1)  // if bit rem is 1, new subset adding
               sum += cur;
          else  // if rem is 0, substracting duplicate subsets
               sum -= cur;
     }
     cout << sum << "\n";
     // cout << r- sum;
}

int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);

     int tests;
     cin >> tests;
     while (tests-- > 0) solve();
}