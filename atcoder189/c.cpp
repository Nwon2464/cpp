#include <algorithm>
#include <array>
#include <bitset>
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
#include <stack>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); i++)
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
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}


const ll LINF = 1001002003004005006ll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
// clang-format on

ll LargestRectangle(vector<ll>& h) {
     ll n = (ll)h.size();

     stack<pair<ll, ll>> st; // hieght, index
     st.push(make_pair(-LINF, -1));
     ll ret = 0;
     rep(i, n) {
          while (h[i] < st.top().first) {
               auto p = st.top();
               st.pop();
               ret = max(ret, (i - st.top().second - 1) * p.first);
               // chmax(ret, (i - st.top().second - 1) * p.first);
          }
          st.push(make_pair(h[i], i));
     }
     while (!st.empty()) {
          auto p = st.top();
          st.pop();
          if (p.first == -LINF) continue;

          ret = max(ret, (n - st.top().second - 1) * p.first);
          // chmax(ret, (n - st.top().second - 1) * p.first);
     }
     return ret;
}
ll LargestRectangle2(vector<ll> heights) {
     ll ans = 0;
     int n = sz(heights);
     stack<pair<ll, ll>> st;
     st.push(make_pair(-LINF, -1));
     rep(i, n) {
          while (heights[i] < st.top().f) {
               auto p = st.top();
               st.pop();
               ans = max(ans, (i - st.top().s - 1) * p.f);
          }
          st.push(make_pair(heights[i], i));
     }
     while (!st.empty()) {
          auto p = st.top();
          st.pop();
          if (p.f == -LINF) continue;
          ans = max(ans, (n - st.top().s - 1) * p.f);
     }
     return ans;
}

void solve() {
     int n;
     cin >> n;
     vector<ll> v(n);
     cin >> v;
     cout << LargestRectangle(v) << endl;
     cout << LargestRectangle2(v) << endl;
}
int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);

     solve();
}
