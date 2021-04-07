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
const int INF = 1e5+1;
int main() {
	int H,W,N,M;
	cin >> H >> W >> N >> M;
	vector<vector<int>> a(H,vector<int> (W));
	vector<vector<int>> visited(H,vector<int> (W));
	
	
	for(int i =0;i<N;i++){
		int x, y;
		cin >> x >> y;
		x--,y--;
		a[x][y] = 1;
	}
	for(int i =0;i<M;i++){
		int x, y;
		cin >> x >> y;
		x--,y--;
		a[x][y] = INF;
	}
	int c;
	for(int i =0; i< H;i++){
	    c = 0;
		for(int j =0;j<W;j++){
			if(a[i][j]==1) c = 1;
			if(a[i][j]==INF) c = 0;			
			if(c == 1) visited[i][j] = c;	
		}
	}

	for(int i =0; i< H;i++){
		c = 0;
		for(int j = W-1;j>=0;j--){
			if(a[i][j]==1) c = 1;
			if(a[i][j]==INF) c = 0;			
			if(c == 1) visited[i][j] = c;	
		}
	}

	for(int j =0; j< W;j++){
		c = 0;
		for(int i = H-1;i>=0;i--){
			if(a[i][j]==1) c = 1;
			if(a[i][j]==INF) c = 0;			
			if(c == 1) visited[i][j] = c;	
		}
	}
	for(int j =0; j< W;j++){
		c = 0;
		for(int i =0;i<H;i++){
			if(a[i][j]==1) c = 1;
			if(a[i][j]==INF) c = 0;			
			if(c == 1) visited[i][j] = c;	
		
		}
	}

	int ans =0;
	for(auto x: visited){
		for(auto y: x){
			ans += y;
		}
	}
	cout << ans;
	debug() << a;
	return 0;
}
