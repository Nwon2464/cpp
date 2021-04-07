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

#define sfl(a)           scanf("%lld",&a)
using ll = long long;

//prime check
bool isPrime(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return true;
}

//prime factorization
void trial_division1(long long n,vector<long long> & factorization) {
	for (long long d = 2; d * d <= n; d++) {
		while (n % d == 0) {
			factorization.push_back(d);
			n /= d;
		}
	}
	if (n > 1){
		factorization.push_back(n);
	}
//return factorization;
}
int main() {
	long long n;
	
	  while(sfl(n) && n){
		vector<long long> factorization;
		map<long long,int> mp;
		trial_division1(n,factorization);
		int sz = factorization.size();
		for(int i =0;  i< sz;i++){
			mp[factorization[i]]++;
		}
		
		for(auto x : mp){
			cout << x.first <<"^"<< x.second << " ";
		}
		cout << "\n";		
	}
	return 0;
}
