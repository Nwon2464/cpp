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
//Codeforces Round #481 (Div. 3) A-Remove Duplicates
//tip : use visted array to check to see if elements are duplicate
using ll = long long;
int vis[1005] ={0};
int main() {
	int n;
	cin >> n;
	vector<int>  a(n);
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	vector<int> ans;
	for(int i=n-1;i>=0;i--){
		if(vis[a[i]] == 0){
			vis[a[i]] = 1;
			ans.push_back(a[i]);
		}
	}
	reverse(ans.begin(),ans.end());
	cout << ans.size() << "\n";
	
	for(auto it : ans){
		cout << it << " ";
	}
	
		
		
	return 0;
}
