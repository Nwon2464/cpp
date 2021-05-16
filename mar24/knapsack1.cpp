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
void max_self(ll& a, ll b)
{
    a = max(a, b);
}
int main()
{
    int n, W;
    cin >> n >> W;
    vector<ll> dp(W + 1);
    //int a[n],b[n];
    for (int i = 0; i < n; ++i) {
        //cin >> a[i] >> b[i];
        int w, v;
        cin >> w >> v;

        for (int curr = W - w; curr >= 0; curr--) {
            max_self(dp[curr + w], dp[curr] + v);
        }
        debug() << imie(dp);
    }

    ll ans = 0;
    for (auto x : dp) {
        ans = max(ans, x);
    }
    cout << ans;

    return 0;
}

//storing weight and value in array
//cin >> n >> W;
//vector<ll> dp(W+1);
//int a[n],b[n];
//for(int i=0;i<n;++i){
//cin >> a[i] >> b[i];
//}

//for(int i =0;i<n;i++){
//for(int curr = W-a[i]; curr>= 0; curr--){

//max_self(dp[curr+a[i]], dp[curr] +b[i]);
//}
//}

//ll ans = 0;
//for(auto x : dp){
//ans = max(ans,x);
//}
//cout << dp[W] << "\n";
