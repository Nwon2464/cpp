#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdio>
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
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define sz(x) (int)(x).size()
#define ms(arr, v) memset(arr, v, sizeof(arr))

// clang-format off


template<typename T_vector>void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) { if (start < 0) start = 0; if (end < 0) end = int(v.size()); for (int i = start; i < end; i++) cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void debug() { cerr << endl; }
template<typename Front, typename... End> void debug(Front H, End... T) { cerr << "debug=>" << H; debug(T...); }
auto random_address = [] {char *p = new char; delete p;return uint64_t(p);};

// clang-format on

void solve() {}

int main() {
     ios::sync_with_stdio(false);
#ifndef WON_DEBUG
     cin.tie(nullptr);
#endif
     // int tests;
     // cin >> tests;

     solve();

     // while (tests-- > 0) solve();
}