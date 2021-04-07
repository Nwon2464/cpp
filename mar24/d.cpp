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
	
	
int main() {
	int n ;
	cin >> n;
	vector<pair<int,ll>> a(n,{0,0});
	for(int i =0;i<n;i++){
		cin >> a[i].second;
		ll v = a[i].second;
		while(v % 3 == 0){		
			v /= 3;
			a[i].first--;
		}
	}
	debug() << a;
	sort(a.begin(),a.end());
	debug() << a;

	for(int i =0;i<n;i++){
		if(i !=0) cout << " ";
		cout << a[i].second;
	}
	cout << endl;
}
