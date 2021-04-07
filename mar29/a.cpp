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
#define FOR(i,n) for (int i = 0; i < (n); ++i)


using ll = long long;
ll gcd(ll x, ll y) {
   
	return y == 0 ? x : gcd(y, x % y);
}
 
ll getSum(ll x) {
	ll s = 0;
	while(x > 0) {
		s += x % 10;
		x /= 10;
	}
	return s;
}
int main(){
	//int ans = gcd(gcd(gcd(a,b),c),d);
	int t;
	cin >> t;
	while(t--) {
		ll x;
		scanf("%lld", &x);
		while(gcd(x, getSum(x)) == 1) x++;
		printf("%lld\n", x);
	}
	return 0;
}
