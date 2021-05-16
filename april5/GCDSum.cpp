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

priority_queue<int> max_pq;
priority_queue<int, vector<int>, greater<int>> min_pq;

using ll = long long;
#define sfl(a) scanf("%lld", &a)

int gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int extendedgcd(int a, int b, int& x, int& y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extendedgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int exgcd(int a, int b, int& x, int& y)
{
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

vector<long long> trial_division1(long long n)
{
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1) {
        factorization.push_back(n);
    }
    return factorization;
}

stack<pair<int, int>> st1;

stack<pair<int, int>> st2;

template <typename T>
vector<T> readVector(int n)
{
    vector<T> res(n);
    for (int i = 0; i < n; i++)
        cin >> res[i];
    return res;
}

int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    auto v = readVector<int>(n);

    map<int, long long> results;

    map<int, int> divisors;
    map<int, int> nextDivisors;
    for (int i = 0; i < n; i++) {
        nextDivisors.clear();
        for (auto& p : divisors) {
            nextDivisors[gcd(p.first, v[i])] += p.second;
        }
        nextDivisors[v[i]]++;

        swap(nextDivisors, divisors);
        for (auto& p : divisors)
            results[p.first] += p.second;
    }

    int q;
    cin >> q;
    while (q-- > 0) {
        int x;
        cin >> x;
        cout << results[x] << endl;
    }
}
