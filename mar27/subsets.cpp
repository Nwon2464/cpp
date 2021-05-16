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
vector<vector<int>> ans;
void search(vector<int>& nums, int i, vector<int> temp)
{
    if (i == (int)nums.size()) {
        ans.push_back(temp);
    } else {
        search(nums, i + 1, temp);
        temp.push_back(nums[i]);
        search(nums, i + 1, temp);
        //temp.pop_back();
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> temp;
    FOR(i, n)
    cin >> nums[i];
    search(nums, 0, temp);
    debug() << ans;
    return 0;
}
