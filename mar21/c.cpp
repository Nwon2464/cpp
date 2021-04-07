#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << "\n" ; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;
int H, W;
const int nax = 1005;
char grid[nax][nax];
const int mod = 1e9+7;

void mod_self(int & a, int b){
	a += b;
	if(a >= mod){
		a -= mod;
	}
}

//dp contest - grid
int main() {
	cin >> H >> W;
	vector<pair<int,int>> directions {{1,0},{0,1}};
	vector< vector<int>> dp (H, vector<int> (W));
	
	for(int i=0; i < H; i++){
		cin >> grid[i];
	}   

	dp[0][0] = 1;
	for(int i=0; i < H; i++){
		for(int j = 0; j<W;j++){
			for(pair<int,int> dir:directions){

				int rowX = dir.first + i;
				int colY = dir.second + j;
				if(rowX < H  && colY < W && grid[rowX][colY] == '.'){
					mod_self(dp[rowX][colY], dp[i][j]);
					
					
				}
			}
			
		}
	}
	cout << dp[H-1][W-1] << " ";
}
