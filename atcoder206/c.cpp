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
const char el = '\n';

// clang-format off
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T_vector>void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {if (start < 0) start = 0; if (end < 0) end = int(v.size()); for (int i = start; i < end; i++) cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');}
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << "(" << v.first << ":" << v.second << ")" << ","; os << "}"; return os; }


auto random_address = [] {char *p = new char; delete p;return uint64_t(p);};
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);
// clang-format on
ll max_pair(int N) {
     ll a = 0, b = 0;
     ll possible = 0;
     for (int i = 2; i <= N; i++) {
          a += b;
          b += 1;
          possible += b;
     }
     return possible;
}
ll max_pair2(ll N) { return (N * (N - 1)) / 2; }

void solve() {
     int N;
     cin >> N;
     vector<int> A(N);
     for (auto &x : A) cin >> x;
     sort(A.begin(), A.end());
     ll mx = max_pair2(N);

     vector<int> freq(N + 1);
     for (int i = 0; i < N - 1; i++) {
          if (A[i] == A[i + 1]) {
               freq[i + 1] = freq[i] + 1;
          }
     }
     for (int i = 0; i < sz(freq); i++) {
          if (freq[i] > 0) {
               mx -= freq[i];
          }
     }
     cout << mx << el;
}
void solve2() {
     int N;
     cin >> N;
     // 5 3 1 4 1 5
     vector<int> A(N);
     map<int, int> mp;
     rep(i, 0, N) cin >> A[i];
     int ans = 0;
     rep(i, 0, N) {
          ans += i - mp[A[i]];
          cout << i << "  " << mp[A[i]] << "  " << mp << el;
          mp[A[i]]++;
     }
     cout << ans << el;
}
int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);

     // int tests;
     // cin >> tests;
     // while (tests-- > 0)
     // solve();
     solve2();
}
