
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sfl(a) scanf("%lld", &a)
#define sz(x) (int)(x).size()
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define mp make_pair
#define f first
#define s second
#define pb push_back
const int mod = 1e9 + 7;
template <typename T>
istream& operator>>(istream& is, vector<T>& vec) {
     for (auto& v : vec) is >> v;
     return is;
}
template <typename A, typename B>
istream& operator>>(istream& cin, pair<A, B>& p) {
     cin >> p.first;
     return cin >> p.second;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
     os << "[";
     for (auto v : vec) os << v << ",";
     os << "]";
     return os;
}
ll a, b, n;

const int N = 1e6 + 5;
ll f[N];

void factmod() {
     f[0] = 1;
     for (int i = 1; i < N; i++) f[i] = f[i - 1] * i % mod;

     // ^^^^^^^^^^^^^^^^^^^^ all factorial [1!,2!,3!,....N]

     // below : find one n!
     // ll res = 1;
     // while (n > 1) {
     // if ((n/mod) % 2)
     // res = mod - res;
     // res = res * f[n%mod] % mod;
     // n /= mod;
     //}

     // return res;
}

bool check(ll t) {
     while (t > 0) {
          if (t % 10 == a || t % 10 == b) {
               t /= 10;
               continue;
          }
          return false;
     }
     return true;
}
ll binpow(ll a, ll b, ll mod) {
     a %= mod;
     ll ans = 1;
     while (b > 0) {
          if (b & 1) ans = ans * a % mod;
          a = a * a % mod;
          b >>= 1;
     }
     return ans;
}

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     cin >> a >> b >> n;
     factmod();
     ll ans = 0;
     for (int i = 0; i <= n; i++) {
          ll t = a * i + b * (n - i);
          if (check(t)) {
               ll aa = f[n];
               ll xx = f[i] * f[n - i];
               xx = binpow(xx, mod - 2, mod);
               ans += (aa * xx) % mod;
               ans %= mod;
               // cout << aa << xx << " ";
          }
     }
     cout << ans << endl;

     return 0;
}
// nCr => 3C3 => 3! / 3!(3-3)!
// i = 0 |   0  333
// i = 1 |   1   33
// i = 2 |   11   3
// i = 3 |   111  0
