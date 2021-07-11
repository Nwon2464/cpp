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
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
#define rep(i, a, b) for (ll i = a; i < (b); ++i)
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

const int MOD = 1e9 + 7;
int print_mod(int a) { return (a % MOD + MOD) % MOD; }
ll mul(ll a, ll b) { return (a * b) % MOD; }

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);

     ll n, k;
     string g;
     cin >> n >> k;
     vector<ll> a(n);
     rep(i, 0, n) cin >> a[i];

     // if k == n
     if (k == n) {
          ll ans2 = 1;
          // never ever use ans += mul(ans,a[i])
          // why? you are adding and multipying the vals at the same time.
          for (int i = 0; i < n; i++) {
               ans2 = mul(ans2, a[i]);
          }
          return cout << print_mod(ans2), 0;
     }

     // check to see if it has posivie
     bool has_pos = false;
     rep(i, 0, n) if (a[i] >= 0) has_pos = true;

     sort(a.begin(), a.end());
     // sort(a.begin(), a.end(), [](int x, int y) { return abs(x) < abs(y); });
     // if all valeus are negative
     // -4,-3,-2,-1
     if (!has_pos) {
          ll ans = 1;
          // cout << a;
          // if k == odd, then multiple of vals are negative
          if (k % 2 == 1) {
               for (ll i = 0; i < k; i++) {
                    ans = mul(ans, a[n - 1 - i]);
               }
          } else {
               // if k == even, then multiple of vals are positives && since we
               // sorted it, first k digits are biggest
               rep(i, 0, k) ans = mul(ans, a[i]);
          }
          cout << print_mod(ans);
          return 0;
          // if k == even
     }

     // if it has pos and neg

     // {5,4,3,2,1,0}  pos
     // {-7,-2,-1}   neg
     int negs = 0;
     rep(i, 0, n) if (a[i] < 0) negs++;

     vector<ll> only_pos(n - negs), only_neg(negs);

     int p_idx = n - negs - 1;
     int n_idx = 0;
     rep(i, 0, n) {
          if (a[i] >= 0)
               only_pos[p_idx--] = a[i];
          else {
               only_neg[n_idx++] = a[i];
          }
     }
     vector<ll> prefix_p((int)only_pos.size() + 1),
         prefix_n((int)only_neg.size() + 1);

     prefix_p[0] = prefix_n[0] = 1;
     rep(i, 1, (ll)only_pos.size() + 1) prefix_p[i] = mul(prefix_p[i - 1], only_pos[i - 1]);
     rep(i, 1, (ll)only_neg.size() + 1) prefix_n[i] = mul(prefix_n[i - 1], only_neg[i - 1]);

     // cout << prefix_p << "prefix " << prefix_n << " " << only_pos << " "
     //      << only_neg;
     ll idx_pos = min(k, (ll)only_pos.size());
     ll idx_neg = k - idx_pos;
     if (idx_neg % 2 == 1) {
          idx_neg++;
          idx_pos--;
     }

     // cout << only_neg[idx_neg] << " " << only_neg[idx_neg + 1];
     while (idx_pos >= 2 && idx_neg + 2 <= negs && only_pos[idx_pos - 1] * (ll)only_pos[idx_pos - 2] < only_neg[idx_neg] * (ll)only_neg[idx_neg + 1]) {
          idx_pos -= 2;
          idx_neg += 2;
     }
     // cout << idx_neg << " " << idx_pos;
     cout << print_mod(mul(prefix_p[idx_pos], prefix_n[idx_neg])) << "\n";

     return 0;
}
