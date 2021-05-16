#include <bits/stdc++.h>

using namespace std;

//Warsaw debug template
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
//End of debug template

using ll = long long;
string s, t;
//[[0,0,0,0,0,0]
//,[0,1,1,1,1,1]
//,[0,1,1,1,2,2]
//,[0,1,1,2,2,2]
//,[0,1,2,2,2,3]]
int main()
{
    cin >> s >> t;
    vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, 0));
    for (int i = 0; i < (int)s.length(); i++) {
        for (int j = 0; j < (int)t.length(); j++) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
            } else {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    cout << dp[s.size()][t.size()];
    int i = s.size(), j = t.size();
    string ans;
    while (i && j) {
        if (s[i - 1] == t[j - 1]) {
            ans = s[i - 1] + ans;
            --i;
            --j;
            continue;
        }
        if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    debug() << dp;
    //cout << ans << "\n" ;
}
