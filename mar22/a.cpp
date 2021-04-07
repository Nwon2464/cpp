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
int n,k;
int main() {
	
	cin >> n >> k;
	vector<int> arr(n);
	vector<int> brr(n);
	


	for(int i=0; i <n;i++)cin >>arr[i];
	for(int i=0; i <n;i++)cin >>brr[i];
	
	
	int prefix[n];
	int suffix[n];
	int prefixSum[n];
	
	for(int i =0; i< n;i++){
		prefix[i] = arr[i] * brr[i] + (i?prefix[i-1]:0);
	}
	
	for(int i =n-1;i>= 0;i--){
		suffix[i] = arr[i] * brr[i] + (i!=n-1? suffix[i+1]:0);
	}
	int ans = 0;
	int sum = 0;
	for(int i =0; i < n;i++){
		sum += arr[i];
		prefixSum[i] = sum;
	}
	
	
	for(int i =0; i+k-1 < n;i++){
		int curr = 0;
		if(i+k< n) curr += suffix[i+k];
		if(i > 0) curr += prefix[i-1];
		int range_prefix = prefixSum[i+k-1];
		if(i >0) range_prefix -= prefixSum[i-1];
		curr += range_prefix;
		
		ans = max(ans,curr);
		
	}
	cout << ans << " " ;
	
}


 
