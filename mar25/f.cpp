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

//Codeforces Round #663 (Div. 2) B-Fix you
//get the minimum amount of cells you have to change
//i.e
//all last row and col have to be 'R' for row or 'D' for col
//you need to check how many last row and last col cells you need to change
//to reach grid[n-1][m-1]
//  RRD
//  DDR  <-- grid[1][m-1] this should be D to reach  grid[n-1][m-1] so +1
//  RRC
//  ||
//  ||
//  it s good because it goes to right so +0 +0
// ans =1  only grid[1][m-1] cell need to change to "D"
using ll = long long;

int main()
{
    int n, m, t;

    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<char>> a(n, vector<char>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += a[i][m - 1] == 'R';
        }
        for (int i = 0; i < m; i++) {
            ans += a[n - 1][i] == 'D';
        }
        cout << ans << "\n";
    }
    return 0;
}
