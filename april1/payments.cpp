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

long long int x[60];
int a;
map<long long int, long long int> check[60];
long long int func(int s, long long int t)
{
    if (s == a)
        return 1;
    if (t == 0)
        return 1;
    if (check[s].find(t) != check[s].end())
        return check[s][t];

    long long int d = x[s + 1] / x[s];
    long long int s1 = 0, s2 = 0;
    if (t % d != 0)
        s1 = func(s + 1, t / d);
    s2 = func(s + 1, (t - 1) / d + 1);
    //debug() << check;
    return check[s][t] = s1 + s2;
}

int main()
{
    long long int b;
    scanf("%d%lld", &a, &b);
    for (int i = 1; i <= a; i++)
        scanf("%lld", &x[i]);
    printf("%lld", func(1, b));
}
