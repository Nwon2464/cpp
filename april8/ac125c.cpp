#include <bits/stdc++.h>

using namespace std;

//---------------------
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
//----------------------

#define rep(i, n) for (int i = 0; i < (n); ++i)

priority_queue<int> max_pq;
priority_queue<int, vector<int>, greater<int>> min_pq;

using ll = long long;

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

//int main() {
//int n;
//cin>>n;
//vector<int> a(n);
//rep(i,n) cin>>a[i];
//vector<int> l(n), r(n);
//rep(i,n) {
//l[i+1] = gcd(l[i], a[i]);
//}
//for (int i = n-1; i >= 1; --i){
//r[i-1] = gcd(r[i], a[i]);
//}
//int ans = 1;
//rep(i,n) ans = max(ans, gcd(l[i],r[i]));
//cout<<ans<<endl;
//debug() << imie(l) imie(r);
//return 0;
//}

//int main() {
//int n;
//cin>>n;
//vector<int> a(n);
//rep(i,n) cin>>a[i];
//vector<int> l(n), r(n);
//int t = 0;
//rep(i,n) {
//l[i] = t;
//t = gcd(a[i],t);
//}

//int ans = 0;
//int t2 = 0;
//for(int i =n-1;i>=0;i--){
//ans = max(ans,gcd(l[i],t2));
//t2 = gcd(t2,a[i]);
//}

//cout<<ans<<endl;
//debug() << imie(l) imie(r);
//return 0;
//}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    rep(i, n) cin >> a[i];
    //4 8 2 6
    //4 4 2 2
    //2 2 2 6
    vector<ll> l(n);
    vector<ll> r(n);
    ll t1 = 0, t2 = 0;
    rep(i, n)
    {
        l[i] = gcd(a[i], t1);
        t1 = l[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        r[i] = gcd(a[i], t2);
        t2 = r[i];
    }
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        if (i == 0)
            ans = max(ans, r[i + 1]);
        else if (i == n - 1)
            ans = max(l[i - 1], ans);
        else {
            ans = max(ans, gcd(l[i - 1], r[i + 1]));
        }
    }

    cout << ans << endl;

    return 0;
}
