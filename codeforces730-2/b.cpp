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

vector<ll> edges[6];
ll indegree[6];
ll dp[6];
vector<ll> topological_order;
void solve() {
     int N, M;
     string S;
     cin >> N >> M >> S;
     for (int i = 0; i < M; i++) {
          int x, y;
          cin >> x >> y;
          --x, --y;
          edges[x].push_back(y);
          ++indegree[y];
     }

     queue<ll> q;

     // if no indegree equals to 0, it has cycles
     // if( cnt < n ) it means cycle
     for (int i = 0; i < N; i++) {
          if (indegree[i] == 0) {
               q.push(i);
          }
     }

     int cnt = 0;
     while (!q.empty()) {
          ++cnt;
          ll x = q.front();
          topological_order.push_back(x);
          q.pop();
          for (auto y : edges[x]) {
               --indegree[y];
               if (indegree[y] == 0) {
                    q.push(y);
               }
          }
     }
     if (cnt < N) {
          cout << "-1" << endl;
          return;
     }

     ll ans = 0;
     for (char c = 'a'; c <= 'z'; c++) {
          ms(dp, 0);
          for (auto x : topological_order) {
               if (S[x] == c) ++dp[x];
               for (auto y : edges[x]) {
                    dp[y] = max(dp[y], dp[x]);
               }
               ans = max(ans, dp[x]);
          }
     }
     cout << ans << endl;
}

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     int t;
     cin >> t;
     while (t--) {
          string S;
          cin >> S;
          int n = sz(S);
          vector<int> alpha(30);
          for (int i = 0; i < n; i++) {
               alpha[S[i] - 'a']++;
          }
          bool flag1 = 0;
          bool flag2 = 0;
          int sum = accumulate(alpha.begin(), alpha.end(), 0);

          for (int i = 0; i < 30; i++) {
               if (alpha[i] == 2) flag1 = 1;
          }

          for (int i = 0; i < 30; i++) {
               if (alpha[i] == 1) sum--;
               if (sum >= 1 && alpha[i] == 0) flag2 = 1;
          }
          if (alpha[0] != 1)
               cout << "NO" << endl;
          else if (flag1 || flag2) {
               cout << "NO" << endl;
          } else {
               cout << "YES" << endl;
          }
     }
}
