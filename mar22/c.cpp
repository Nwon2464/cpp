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
//codeforce B- Lecture Sleep
int n,k,p,a[2005],b[2005];
void solve(){
	sort(a,a+n);sort(b,b+k);
	int ans=2*0x3f3f3f3f;
	for(int i =0; i < k-n; i++){
		int sum = 0;
		for(int j = 0; j <n ;j++){
			sum = max(sum,abs(a[j]- b[i+j]) + abs(b[i+j] - p));
		}
		ans = min(sum,ans);
	}
	cout<<ans<<endl;
}

int main(){
	cin>>n>>k>>p;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<k;i++)
		cin>>b[i];
	solve();
}
