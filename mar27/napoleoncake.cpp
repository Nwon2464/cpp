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
//Codeforces Round #707 (Div. 2, based on Moscow Open Olympiad in Informatics)
//B-Napoleon Cake
using ll = long long;

int main() {
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> ans(n);
		FOR(i,n) cin >> a[i];
		int temp = 0;
		for(int i = n-1;i>=0;i--){
			//get the max for every time to decide you put 1 or 0
			temp = max(a[i],temp);
			if(temp){
				ans[i] = 1;
				--temp;
			}else{
				a[i] = 0;
			}
		}
		for(auto x: ans){
			cout << x << " ";
		}
		cout << endl;
		
	}
	return 0;
}
