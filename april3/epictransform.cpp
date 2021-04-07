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

int main() {
	
	int t;
	cin >> t;
	while(t--){
		priority_queue<pair<int,int>> pq;
		map<int,int> mp;
		int n;
		cin >> n;
		
		FOR(i,n) {
			int x;
			cin >> x;
			mp[x]++;
		}
		for(auto [x,y] : mp){
			pq.push({y,x});
		}
		int sz = n;
		while(pq.size() >= 2){
			auto [p1,p2] = pq.top();
			--p1;
			pq.pop();
			auto [p3,p4] = pq.top();
			--p3;
			pq.pop();
			sz -= 2;
			
			if(p1){
				pq.push({p1,p2});
			}
			if(p3){
				pq.push({p3,p4});
			}
			
		}
		cout << sz << "\n";
	}
	
	return 0;
}
