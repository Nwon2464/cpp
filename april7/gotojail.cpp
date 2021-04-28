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

priority_queue<int> max_pq;
priority_queue<int, vector<int>, greater<int>> min_pq;

using ll = long long;

int main() {
	int n;
	cin >> n;
	vector<vector<int> > a(100,vector<int>(2));
	
	for(int i =0; i<n;i++){
		cin >> a[i][0] >> a[i][1];
	}
	bool flag = false;
	for(int i =0; i +2<n;i++){
		if(a[i][0] == a[i][1] && a[i+1][0] == a[i+1][1] && a[i+2][0]== a[i+2][1]){
			flag = true;
		}		
	}
	cout << (flag? "Yes\n" : "No" );
	return 0;
}

//more decent method

int main(){
	int n;
	cin >> n;
	int cnt = 0;
	for(int i =0;i<n;i++){
		int a,b;
		cin >> a>>b;
		
		if( a== b) cnt++;
		else{
			cnt = 0;
		}
		if(cnt ==3){
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No";
	return 0;
}
