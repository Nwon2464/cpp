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
#define REP(i,n) for (int i = 0; i < (n); ++i)


using ll = long long;
const int m = 1e9+7;
ll gcd(ll a,ll b){
	return b == 0 ? a : gcd(b,a%b);
}

// numbers
int findGCD(vector<int> arr, int n)
{
    int result = arr[0];
    for (int i = 1; i < n; i++)
        result = gcd(arr[i], result);
  
    return result;
}


int main() {
	
	string s;
	cin >> s;
	int sz = s.size();
	vector<int> a(3);
	REP(i,sz) a[(s[i] - '0')%3]++;
	
	int sum = 0;
	REP(i,3) sum += a[i] * i;
	int ans = 1e9;
	REP(i,3)REP(j,3){
		if(a[1] < i) continue;
		if(a[2] < j) continue;
		if(i + j == sz) continue;
		
		int t = sum;
		t -= i * 1;
		t -= j * 2;
		if(t % 3 == 0) ans = min(ans,i+j);
	}
	if(ans == 1e9) ans = -1;
	cout << ans << endl;
	 
	
	return 0;
}
