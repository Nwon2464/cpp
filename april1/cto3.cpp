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
	string str;
	cin >> str;
	int n = str.size();
	vector<int> a(3);
	FOR(i,n) a[(str[i] - '0') % 3]++;
	
	int dup = 0;
	for(int i =1; i< 3; i++) dup += a[i] * i;
	
	int ans = 1e9;
	for(int i = 0;i<3;i++){
		for(int j =0;j<3;j++){
			if(a[1] < i) continue;
			if(a[2] < j) continue;
			if(i+j == n) continue;
			int sz = dup;
			sz -= 1 * i;
			sz -= 2 * j;
			if(sz % 3 == 0) ans = min(ans,i+j);
	
		}
	}
	if(ans == 1e9) ans = -1;
	cout << ans;
	return 0;
}
