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
 

using ll = long long;
using ull = unsigned long long;
//1 2   1 3             3 => 2
//3 4   2 4
//1,0 
//3-2 ,3-3
//1.1

//row   col
const int mod = 1e6;
int main() {
	int t;
	cin >> t;
	while(t--){
	ull n,m,x;
	cin >> n >> m >> x;
	    x--;
	    ll r = x/n;
	    ll c = x%n;
	    
	    ll ans = c * m + r +1;
	    
		cout << ans  << '\n';
	}
	return 0;
}

