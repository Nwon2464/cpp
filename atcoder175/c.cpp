#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define mp make_pair
#define f first
#define s second
#define pb push_back

// clang-format off
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>    ostream& operator<<(ostream &os, const T_container &v)  { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void debug() { cerr << endl; }
template<typename Head, typename... Tail> void debug(Head H, Tail... T) { cerr << ' ' << H; debug(T...); }
auto random_address = [] {char *p = new char; delete p;return uint64_t(p);};
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);
// clang-format on

const int N = 100;
bool pr[N];
ll fact[N];
vector<int> vals, cnt(N + 1, 0);
void sieve() {
     ms(pr, 1);
     for (int i = 2; i * i <= N; i++) {
          for (int j = i * i; j <= N; j += i) {
               if (pr[j]) {
                    pr[j] = 0;
               }
          }
     }
     for (int i = 2; i <= N; i++) {
          if (pr[i]) {
               vals.push_back(i);
          }
     }
}

void solve() {  // ll x = 1;

     // for (ll i = b + 1; it <= a; i++) {
     //   x = x * i;
     // }
}
int main() {
     ios::sync_with_stdio(0);
     cin.tie(NULL);
     std::vector<char> v;

     sieve();

     // for (auto it = vals.begin(); it != vals.end(); ++it) {
     //   int c = *it;
     //   for (int i = c; i < N; i += c) {
     //     cnt[i]++;
     //   }
     // }
     for (int i = 0; i < 3; i++) {
          cout << "A";
     }
     for (auto it = vals.begin(); it != vals.end(); ++it) {
          int p = *it;
          int t = p;
          while (1) {
               for (int i = t; i <= N; i += t) {
                    ++cnt[i];
               }
               if ((ll)t * p > N) break;

               t *= p;
          }
     }

     vector<ll> factcnt(N + 1, 0);
     for (int i = 1; i <= N; ++i) {
          factcnt[i] = factcnt[i - 1] + cnt[i];
     }
     int t;

     cin >> t;
     while (t--) {
          int a, b;
          cin >> a >> b;
          ll ans = factcnt[a] - factcnt[b];

          cout << ans << "\n";
     }
}
