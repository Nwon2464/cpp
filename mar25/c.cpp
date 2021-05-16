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

//Codeforces Round #663 (Div. 2) C-cyclic permutations
//formula n! - 2^(n-1)
//input 4  => 4! - 2^(4-1) = 24 - 8 = 16
using ll = long long;
const int mod = 1e9 + 7;
int main()
{
    int n;
    cin >> n;
    ll x = 1, y = 1, a = 1, b = 1;
    for (int i = 2; i <= n; i++) {
        x = (x * i) % mod;
        y = (y * 2) % mod;
    }
    cout << (x - y + mod) % mod;
}
