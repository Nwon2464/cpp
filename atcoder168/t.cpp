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
int main() {
     int N, L;
     cin >> N >> L;
     vector<int> A(N);
     rep(i, 0, N) cin >> A[i];
     sort(A.begin(), A.end());
     int res = 0;
     for (int i = 0; i < N - 1; i++) {
          res = max(res, A[i + 1] - A[i]);
     }
     printf("%.10f", res / 2.);

     return 0;
}

// 0 3 6 7

// 1 -1
//   +1 -1
//+1       -1

// 2  0 -1 -1

// 2  2 1  0  prefix sum

// int main() {
//      ios::sync_with_stdio(0);
//      cin.tie(0);

//      int n;
//      while (~scanf("%d", &n)) {
//           vector<int> L(n);
//           vector<int> R(n);
//           for (int i = 0; i < n; ++i) scanf("%d%d", &L[i], &R[i]), --L[i];
//           vector<int> values;
//           rep(i, 0, n) {
//                values.push_back(L[i]);
//                values.push_back(R[i]);
//           }
//           sort(values.begin(), values.end());
//           values.erase(unique(values.begin(), values.end()), values.end());
//           int X = (int)values.size();
//           vector<int> add(X + 1);
//           rep(i, 0, n) {
//                int l = (int)(lower_bound(values.begin(), values.end(), L[i])
//                -
//                              values.begin());
//                int r = (int)(lower_bound(values.begin(), values.end(), R[i])
//                -
//                              values.begin());
//                ++add[l], --add[r];
//           }
//           rep(i, 0, X) add[i + 1] += add[i];
//           vector<int> sum(X + 1);
//           rep(i, 0, X) sum[i + 1] = sum[i] + (add[i] >= 2);
//           int ans = -1;
//           rep(i, 0, n) {
//                int l = (int)(lower_bound(values.begin(), values.end(), L[i])
//                -
//                              values.begin());
//                int r = (int)(lower_bound(values.begin(), values.end(), R[i])
//                -
//                              values.begin());
//                if (sum[r] - sum[l] == r - l) {
//                     ans = i;
//                     break;
//                }
//           }
//           printf("%d\n", ans == -1 ? ans : ans + 1);
//      }
//      return 0;
// }

// #include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>

// using namespace std;
// using namespace __gnu_pbds;

// typedef long long ll;
// typedef vector<int> vi;
// typedef pair<int, int> pii;
// template <class T> using Tree = tree<T, null_type, less<T>,
// rb_tree_tag,tree_order_statistics_node_update>;

// #define FOR(i, a, b) for (int i=a; i<(b); i++)
// #define F0R(i, a) for (int i=0; i<(a); i++)
// #define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
// #define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

// #define sz(x) (int)(x).size()
// #define mp make_pair
// #define pb push_back
// #define f first
// #define s second
// #define lb lower_bound
// #define ub upper_bound

// const int MOD = 1000000007;

// int n;
// map<int,int> m;
// vector<pii> tv;

// template<int SZ> struct LazySegTree {
//     int mn[2*SZ], lazy[2*SZ];

//     LazySegTree() {
//         memset (mn,0,sizeof mn);
//         memset (lazy,0,sizeof lazy);
//     }

//     void push(int ind, int L, int R) {
//         mn[ind] += lazy[ind];
//         if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind];
//         lazy[ind] = 0;
//     }

//     void pull(int ind) {
//         mn[ind] = min(mn[2*ind],mn[2*ind+1]);
//     }

//     void build() {
//         for (int i = SZ-1; i > 0; --i) pull(i);
//     }

//     int qmin(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
//         push(ind,L,R);
//         if (lo > R || L > hi) return MOD;
//         if (lo <= L && R <= hi) return mn[ind];

//         int M = (L+R)/2;
//         return min(qmin(lo,hi,2*ind,L,M),qmin(lo,hi,2*ind+1,M+1,R));
//     }

//     void upd(int lo, int hi, int inc, int ind = 1, int L = 0, int R = SZ-1) {
//         push(ind,L,R);
//         if (hi < L || R < lo) return;
//         if (lo <= L && R <= hi) {
//             lazy[ind] = inc;
//             push(ind,L,R);
//             return;
//         }

//         int M = (L+R)/2;
//         upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
//         pull(ind);
//     }
// };

// LazySegTree<1<<19> L;

// int main() {
//      ios_base::sync_with_stdio(0);cin.tie(0);
//      cin >> n;
//      F0R(i,n) {
//          int l,r; cin >> l >> r;
//          tv.pb({l,r});
//          m[l] = m[r+1] = 0;
//      }
//      int co = 0;
//      for(auto& a: m) a.s = co++;
//      for (auto& a: tv) {
//          a.f = m[a.f], a.s = m[a.s+1]-1;
//          L.upd(a.f,a.s,1);
//      }
//      F0R(i,tv.size()) {
//          if (L.qmin(tv[i].f,tv[i].s) != 1) {
//              cout << i+1 << "\n";
//              return 0;
//          }
//      }
//      cout << -1;

// }

// // read!
// // ll vs. int!