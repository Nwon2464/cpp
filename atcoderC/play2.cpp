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
#include <string>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
// #define rep(i, a, b) for (int i = a; i < (b); ++i)
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

template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) { cin >> p.first;return cin >> p.second;}


auto random_address = [] {char *p = new char; delete p;return uint64_t(p);};
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);

// clang-format on
const ll mod = 1e9 + 7;
template <typename T, typename Compare>
vector<int> build_cartesian_tree(const vector<T> &A, const Compare &&compare) {
     // building cartesian tree O(N)
     int n = int(A.size());
     vector<int> parent(n, -1);
     vector<int> stack;

     for (int i = 0; i < n; i++) {
          int erased = -1;

          while (!stack.empty() && compare(A[i], A[stack.back()])) {
               erased = stack.back();
               stack.pop_back();
          }

          parent[i] = stack.empty() ? -1 : stack.back();

          if (erased >= 0) parent[erased] = i;

          stack.push_back(i);
     }

     return parent;
}

static int largest_bit(int x) { return 31 - __builtin_clz(x); }

int main() {
     vector<int> parents = {-1, 0, 0, 1, 1, 2, 2};
     int log = 0;
     int n = sz(parents);
     while ((1 << (log + 1)) <= n) {
          log++;
     }
     log++;
     vector<vector<int>> up;
     vector<int> depth;
     up = vector<vector<int>>(n, vector<int>(log));

     depth = vector<int>(n);
     parents[0] = 0;
     for (int v = 0; v < n; v++) {
          up[v][0] = parents[v];
          if (v != 0) {
               depth[v] = depth[parents[v]] + 1;
          }
          for (int j = 1; j < log; j++) {
               up[v][j] = up[up[v][j - 1]][j - 1];
               // cout << up[v][j - 1] << " " << j - 1 << endl;
               // cout << up[v][j]
          }
     }
     // cout << up << endl;
     auto kth = [&](int node, int k) -> int {
          if (depth[node] < k) return -1;
          for (int j = 0; j < log; j++) {
               if (k & (1 << j)) {
                    node = up[node][j];
               }
          }
          return node;
     };
     // cout << kth(3, 1) << endl;
     // cout << kth(5, 2) << endl;
     // cout << kth(6, 3) << endl;
     return 0;
}

//       0                -1
//    1      2          0     0
//  3   4  5   6      1   1  2  2
