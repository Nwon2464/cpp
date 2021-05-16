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
#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define FORr(i, n) for (int i = (n - 1); i >= 0; --i)

using ll = long long;

int main()
{

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n + 1);
        vector<ll> b(n + 1);
        vector<ll> tm(n);
        FOR(i, n)
        cin >> a[i + 1] >> b[i + 1];
        FOR(i, n)
        cin >> tm[i];
        ll time = 0;
        //2 10
        //4 12
        for (int i = 1; i <= n; i++) {
            time += a[i] - b[i - 1] + tm[i - 1];
            if (i != n) {
                time = max(b[i], time + (b[i] - a[i] + 1) / 2);
            }
        }
        cout << time << "\n";
    }
    return 0;
}
