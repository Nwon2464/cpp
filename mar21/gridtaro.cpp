#include <bits/stdc++.h>

using namespace std;

// Warsaw debug template
#define LOCAL
#define sim template <class c
#define ris return *this
#define dor > debug& operator<<
#define eni(x)                                                                   \
    sim > typename enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) \
    {
sim > struct rge {
    c b, e;
};
sim > rge<c> range(c i, c j) { return rge<c> { i, j }; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
    ~debug()
    {
        cerr << endl;
    }
    eni(!=) cerr << boolalpha << i;
    ris;
} eni(==) ris << range(begin(i), end(i));
}
sim, class b dor(pair<b, c> d)
{
    ris << "(" << d.first << "," << d.second << ")";
}
sim dor(rge<c> d)
{
    *this << "[";
    for (auto it = d.b; it != d.e; ++it)
        *this << "," + (it == d.b) << *it;
    ris << "]";
}
#else
    sim dor(const c&)
    {
        ris;
    }
#endif
}
;
#define imie(...) "[" << #__VA_ARGS__ ":" << (__VA_ARGS__) << "]"
// End of debug template

using ll = long long;

template <typename T>
void max_self(T& a, T b)
{
    a = max(a, b);
}
bool first(pair<int, int> p) { return p.first == 0 || p.second == 0; }

string s, t;
const int INF = 1e9 + 5;
int main()
{
    // cin >> s >> t;
    // vector<vector<pair<int, pair<int, int>>>> dp(
    //     s.length() + 1,
    //     vector<pair<int, pair<int, int>>>(t.length() + 1, {0, {0, 0}}));
    // dp[0][0]= {0,{0,0}};
    // for (int i = 0; i < (int)s.length(); i++) {
    //   for (int j = 0; j < (int)t.length(); j++) {
    //     if (s[i] == t[j]) {
    //       max_self(dp[i + 1][j + 1],
    //                make_pair(dp[i][j].first + 1, make_pair(i, j)));
    //     }
    //     max_self(dp[i + 1][j], make_pair(dp[i][j].first, make_pair(i, j)));

    //     max_self(dp[i][j + 1], make_pair(dp[i][j].first, make_pair(i, j)));
    //   }
    // }

    // pair<int, pair<int, int>> ans = {0, {0, 0}};
    // for (int i = 0; i <= (int)s.length(); ++i) {
    //   for (int j = 0; j <= (int)t.length(); ++j) {
    //     max_self(ans, make_pair(dp[i][j].first, make_pair(i, j)));
    //   }
    // }
    // string str;

    // pair<int, int> cur = ans.second;
    // while (!first(cur)) {
    //   int i = cur.first;
    //   int j = cur.second;
    //   pair<int, int> prev = dp[i][j].second;

    //   if (prev == make_pair(i - 1, j - 1)) {
    //     assert(s[i - 1] == t[j - 1]);
    //     str += s[i - 1];
    //   }
    //   cur = prev;
    // }
    // reverse(str.end(), str.begin());
    // cout << str;
}
