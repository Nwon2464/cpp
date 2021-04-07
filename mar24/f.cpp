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
	int n; 
	cin >> n;
	map<int,int> dp;
	vector<int> a(n);
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	int max_idx = 0;
	int max_val = 0;
	for(int i =0;i<n;i++){
		dp[a[i]]= dp[a[i]-1]+1;
		if(max_val < dp[a[i]]){
			max_val = dp[a[i]];
			max_idx = a[i];		
		}
	}
	
	vector<int> ans;
	for(int i =n-1; i>=0;i--){
		if(max_idx == a[i]){
			ans.push_back(i+1);
			max_idx--;
		}
	}
	debug() << imie(max_val) imie(ans) imie(dp);
	
	reverse(ans.begin(),ans.end());
	
	cout << max_val << "\n";
	for(int i=0;i<(int)ans.size();i++){
		if(i !=0){
			cout << " ";
		}
		cout << ans[i];
	}
	cout << endl;
	
	
	
	
	return 0;
}
