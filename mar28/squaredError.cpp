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
#define REP(i,a,b) for (int i = a; i < b; i++)

using ll = long long;
const int maxA = 200;
//void search(vector<vector<int>> &per,vector<int> &temp,int n,vector<bool> &visited){
	//if(n == (int)temp.size()){
		//per.push_back(temp);
	//}else{
		//for(int i =1; i <= n; i++){
			//if(visited[i]) continue;
			//visited[i] = true;
			//temp.push_back(i);
			//search(per,temp,n,visited);
			//visited[i] = false;
			//temp.pop_back();
		//}
	//}
//}
int main() {
	
	int n;
	cin >> n;
	vector<int> a(n);
	FOR(i,n) cin >> a[i];
	vector<int> d(maxA*2+1);
	ll ans = 0;
	for(int i=0;i<n;i++){
		for(int aj= -maxA;aj<=maxA;++aj){
			int c = d[maxA+aj]; //d[400 + -400]
			int x = a[i] - aj;  //a[i] = 2 - -400
			ans += (ll)x*x*c;
		}
		d[maxA+a[i]]++;
	} 
	
	cout << ans;
	return 0;
}
