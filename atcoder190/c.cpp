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

//Bowls and Dishes
//k ppl will put a ball on c or d
//bit if(setbit) put a ball on c else put a ball on d
//conditions to check if dish a and dish b has both balls on them
int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     int n, m;
     cin >> n >> m;
     vector<int> a(m), b(m);
     rep(i, 0, m) cin >> a[i] >> b[i];

     int k;
     cin >> k;
     vector<int> c(k), d(k);
     rep(i, 0, k) cin >> c[i] >> d[i];
     int ans = 0;
     rep(msk, 0, 1 << k) {
          vector<int> dish(n + 1);
          rep(i, 0, k) {

               if (msk & (1 << i)) {
                    dish[d[i]]++;
               } else {
                    dish[c[i]]++;
               }
          }
          int cnt = 0;
          rep(i, 0, m) {
               if (dish[a[i]] && dish[b[i]])
                    cnt++;
               else {
                    continue;
               }
          }
          ans = max(ans, cnt);
     }

     cout << ans;
}