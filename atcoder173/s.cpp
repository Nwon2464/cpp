#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
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
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T_vector>void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {if (start < 0) start = 0; if (end < 0) end = int(v.size()); for (int i = start; i < end; i++) cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');}
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << "(" << v.first << ":" << v.second << ")" << ","; os << "}"; return os; }


auto random_address = [] {char *p = new char; delete p;return uint64_t(p);};
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);
// clang-format on

void solve() { }

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);

     int t;
     cin >> t;
     // TC  10^14

     while (t--) {
          //10^4
          int n;
          cin >> n;

          vector<int> a(n);
          rep(i, 0, n) cin >> a[i];

          priority_queue<int> pq;
          priority_queue<int, vector<int>, greater<int>> minp;
          int temp = 0;
          vector<int> mx, mn;
          for (int i = 0; i < n; i++) { // 2*10^5
               bool max_seen = temp == a[i];
               while (temp + 1 < a[i]) { // 2*10^5
                    temp++;
                    pq.push(temp);
                    minp.push(temp);
               }
               temp = a[i];
               if (!max_seen) {
                    mx.push_back(a[i]);
                    mn.push_back(a[i]);
               } else {
                    int x = pq.top();
                    mx.push_back(x);
                    pq.pop();
                    int y = minp.top();
                    mn.push_back(y);
                    minp.pop();
               }
          }
          output_vector(mn);
          output_vector(mx);
     }
}

// p[i] != i p[p[i]] = i

// 6
// 2 1 4 3 6 5
