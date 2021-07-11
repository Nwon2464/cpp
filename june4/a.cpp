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

vector<int> to_digits(int x) {
     vector<int> v;

     while (x) {
          int t = x % 10;
          v.push_back(t);
          x /= 10;
     }
     return v;
}
int to_num(vector<int> a) {
     int n = a.size();
     int res = 0;
     int p = 1;
     for (int i = n - 1; i >= 0; i--) {
          res += p * a[i];
          p *= 10;
     }
     return res;
}
int g1(int n) {
     auto v = to_digits(n);
     sort(v.rbegin(), v.rend());
     return to_num(v);
}
int g2(int n) {
     auto v = to_digits(n);
     sort(v.begin(), v.end());
     return to_num(v);
}
int f(int n) {
     return g1(n) - g2(n);
}

ll f1(string& x) {
     sort(x.rbegin(), x.rend());
     return stoll(x);
}
ll f2(string& x) {
     sort(x.begin(), x.end());
     return stoll(x);
}
int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     string n;
     int k;
     cin >> n >> k;
     rep(i, 0, k) {
          ll x = f1(n) - f2(n);
          n = to_string(x);
     }
     cout << n << endl;
}
