#include <bits/stdc++.h>
using namespace std;
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
        cerr << "\n";
    }
    eni(!=) cerr << boolalpha << i;
    ris;
} eni(==) ris << range(begin(i), end(i));
}
sim, class b dor(pair<b, c> d)
{
    ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d)
{
    *this << "[";
    for (auto it = d.b; it != d.e; ++it)
        *this << ", " + 2 * (it == d.b) << *it;
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
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;
// codeforce - B lecture Sleep
int main()
{

    int n, k, p;
    cin >> n >> k >> p;
    int arr[n], brr[k];

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    for (int i = 0; i < k; i++)
        cin >> brr[i];
    sort(brr, brr + k);

    int dp[k + 1][n + 1];

    const int INF = 1e9 + 5;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;

    // n denotes number of people
    // k deonotes number of keys
    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= n; j++) {

            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            if (j < n) {
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], max(dp[i][j], abs(arr[j] - brr[i]) + abs(brr[i] - p)));
            }
        }
    }

    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j])

                       cout
        << dp[k][n];
}
