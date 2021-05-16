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

using ll = long long;

int main()
{

    int t;
    cin >> t;
    while (t--) {
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        int w, b;
        cin >> w >> b;
        //vector<vector<int>> a(2,vector<int> (n,1));
        //0 = "white" 1 = "black";
        //for(int j=0;j<k1;j++){
        //a[0][j] = 0;
        //for(int j=0;j<k2;j++){
        //a[1][j] = 0;
        //}
        int total = 2 * n;
        int tw = k1 + k2;
        int tb = total - tw;

        if (tw >= w * 2 && tb >= b * 2)
            cout << "YES\n";
        else {
            cout << "NO\n";
        }
        //cout <<  ? : << endl;
        //int cnt = w+b;
        //vector<vector<bool>> visited(2,vector<bool> (n,false));

        //for(int i =0;i<2;i++){
        //for(int j =0;j<n;j++){
        //if(!visited[i][j] && a[i+1][j] == 0 || a[i][j+1] == 0){
        //cnt--;
        //visited[i][j] = true;
        //}
        //}
        //}
    }

    return 0;
}
