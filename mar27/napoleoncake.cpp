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
//Codeforces Round #707 (Div. 2, based on Moscow Open Olympiad in Informatics)
//B-Napoleon Cake
using ll = long long;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> ans(n);
        FOR(i, n)
        cin >> a[i];
        int temp = 0;
        for (int i = n - 1; i >= 0; i--) {
            //get the max for every time to decide you put 1 or 0
            temp = max(a[i], temp);
            if (temp) {
                ans[i] = 1;
                --temp;
            } else {
                a[i] = 0;
            }
        }
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}

int getUsed(string s, char takeFirst)
{
    int res = 0;
    bool seen = false;
    FOR(i, (int)s.size())
    {
        if (s[i] == takeFirst) {
            seen = true;
        }
        if (seen) {
            res = res | (1 << (s[i] - 'a'));
        }
    }
    return res;
}

int main()
{

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<int> a(n);

        FOR(i, n)
        cin >> a[i];

        priority_queue<int> Maxpq;
        priority_queue<int, vector<int>, greater<int>> Minpq;

        vector<int> maxAns(n);
        vector<int> minAns(n);

        int maxSeen = 0;

        for (int i = 0; i < n; i++) {
            bool is = maxSeen != a[i];
            while (maxSeen + 1 < a[i]) {
                maxSeen++;
                Minpq.push(maxSeen);
                Maxpq.push(maxSeen);
            }
            maxSeen = a[i];
            if (is) {
                maxAns[i] = a[i];
                minAns[i] = a[i];
            } else {
                int maxVal = Maxpq.top();
                int minVal = Minpq.top();

                Maxpq.pop();
                Minpq.pop();

                maxAns[i] = maxVal;
                minAns[i] = minVal;
            }
        }
        for (auto x : minAns) {
            cout << x << " ";
        }
        cout << endl;
        for (auto x : maxAns) {
            cout << x << " ";
        }
        cout << endl;

    //string s;
    //cin >> s;
    //int n = s.size();
    //vector<int> occur[26];
    //for(int i = n-1;i>=0;i--){
    //occur[s[i]-'a'].push_back(i);
    //}
    //int start = 0;

    //while(true){
    //bool isOK = false;
    //for(int use = 25; use>=0;use--){
    //if(!occur[use].empty()){
    //int where = occur[use].back();
    //bool all_present = true;
    //for(int c = 0;c<26;c++){
    //if(!occur[c].empty()){
    //if(occur[c][0] < where){
    //all_present = false;
    //break;
    //}
    //}
    //}
    //if(all_present){
    //cout << s[where];
    //start = where +1;
    //occur[s[where]-'a'].clear();
    //for(int c = 0;c<26;c++){
    //while(!occur[c].empty() && occur[c].back() < start){
    //occur[c].pop_back();
    //}
    //}
    //isOK = true;
    //break;
    //}

    //}
    //}
    //if(!isOK) break;
    //}
    //cout << endl;
