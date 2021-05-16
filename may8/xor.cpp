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

const int nax = 1e8;
vector<char> is_prime(nax + 1, true);
vector<int> a;

void sieve() {
     for (int i = 2; i * i <= nax; i++) {
          if (is_prime[i]) {
               for (int j = i * i; j <= nax; j++) {
                    is_prime[j] = 1;
               }
          }
     }

     for (int i = 2; i <= nax; i++) {
          if (is_prime[i]) {
               a.push_back(i);
          }
     }
     for (int i = 1; i < (int)a.size(); i += 100) {
          cout << a[i - 1] << "\n";
     }
}
int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);

     int x = 5;
     if (x == 3)
          return 1;
     else {
          cout << " A";
     }

     // sieve();

     map<int, int> map;

     vector<int> a = {4, 6, 1, 2, 3, 3, 1, 2, 4, 6};
     int n = (int)a.size();

     int t = 0;
     rep(i, 0, n) { map[a[i] ^ t]++; }
     int maxlen = 0, prexor = 0;
     for (int i = 0; i < n; i++) {
          prexor = prexor ^ a[i];
          if (prexor == 0) {
               maxlen = i + 1;
          } else if (map.find(prexor) != map.end()) {
               maxlen = max(maxlen, i - map[prexor]);
          } else {
               map[prexor] = i;
          }
     }

     cout << maxlen;

     return 0;
}
