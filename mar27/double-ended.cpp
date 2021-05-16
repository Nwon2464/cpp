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

int main()
{

    //dp
    //while(t--){
    //string a,b;

    //cin >> a >> b;
    //int s1 = a.length();
    //int s2 = b.length();
    //vector<vector<int>> dp(s1+1,vector<int>(s2+1));
    //dp[0][0] = 0;
    //FOR(i,s1)FOR(j,s2){
    //if(a[i] == b[j]){
    //dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j] + 1);
    //}
    //}

    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int ans = 0;
    for (int len = 1; len <= min(n, m); len++) {
        for (int i = 0; i + len <= n; i++) {
            for (int j = 0; j + len <= m; j++) {
                if (a.substr(i, len) == b.substr(j, len)) {
                    ans = max(ans, len);
                }
            }
        }
    }
    cout << a.size() + b.size() - 2 * ans << "\n";
    //greedy
    //int w; cin >> w;
    //int n,m,maxi;
    //while (w--) {
    //string a,b;
    //cin >> a >> b;
    //n=a.size(), m=b.size(), maxi=0;
    //for (int i=0; i<n; i++) {
    //for (int j=0; j<m; j++) {
    //int db=0;
    //for (int k=0; ; k++) {
    //if (i+k>=n || j+k>=m || a[i+k]!=b[j+k]) {
    //break;
    //}
    //db++;
    //}
    //maxi=max(maxi, db);
    //}
    //}
    //cout << n + m -(2*maxi) << "\n";
    //}
    return 0;
}
