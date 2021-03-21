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
const int INF = 1e9+5;
int n,k;
int main() {
	cin >> n >> k;
	vector<int> arr(n);
	vector<int> dp(n,INF);
	for(int i= 0; i< n;i++){
		cin >> arr[i];
	}
	dp[0] = 0;
	for(int i =0; i <n;i++){
		for(int j=i+1; j<= i+k;j++){
			if(j <n){
				dp[j] = min(dp[j],dp[i] + abs(arr[i] - arr[j]));
			}
		}
	}
	cout << dp[n-1] ;
	

}
