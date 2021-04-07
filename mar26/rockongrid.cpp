#include <bits/stdc++.h>

using namespace std;

//Warsaw debug template
#define LOCAL
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
    enable_if<sizeof dud<c>(0) x 1,debug&>::type operator<<(c i){
sim > struct rge {c b,e;};
sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug{
#ifdef LOCAL
~debug() {cerr<<endl; }
eni(!=) cerr<< boolalpha << i; ris;}
eni(==) ris <<range(begin(i),end(i)); }
sim, class b dor(pair<b,c> d){
ris<<"("<<d.first<<","<<d.second<<")";
}
sim dor(rge<c> d){
    *this << "[";
    for(auto it=d.b;it!=d.e;++it)
        *this <<"," +(it==d.b)<< *it;
    ris<<"]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) "["<<#__VA_ARGS__":"<<(__VA_ARGS__)<<"]"
//End of debug template
 
#define rep(i,n) for (int i = 0; i < (n); ++i)

using ll = long long;

using P = pair<int,int>;

int main() {
	int h,w,n;
	cin >> h >> w >> n;
	vector<int> a(w,h), b(h,w);
	rep(i,n) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		a[y] = min(a[y], x);
		b[x] = min(b[x], y);
	}
	ll ans = 0;
	rep(y,b[0]) ans += a[y];
	rep(x,a[0]) ans += b[x];
	
	fenwick_tree<int> t(w);
	
	rep(y,b[0]) t.add(y,1);
    
    vector<vector<int>> ends(h+1);
	
	rep(y,b[0]) ends[a[y]].push_back(y);
	rep(x,a[0]) {
	  for (int y : ends[x]) t.add(y, -1);
		ans -= t.sum(0,b[x]);
	  }
    cout << ans;
	return 0;
}
