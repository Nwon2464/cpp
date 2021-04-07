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


vector<pair<long long, int> > pf;
vector<int> pr;

void seive(ll n){
	vector<ll> lp(n+1);

	for (int i=2; i<=n; ++i) {
	if (lp[i] == 0) {
		lp[i] = i;
		pr.push_back (i);
	}
	for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=n; ++j)
		lp[i * pr[j]] = pr[j];
	}
	//return pr;
}

vector<pair<long long, int> > optimized_trial_division(long long n) {
    for (auto p : pr) {
        if (p*p > n) break;
        int count = 0;
        while (n%p==0) ++count, n/=p;
        if (count) pf.push_back({p, count});
    }
    if (n>1) pf.push_back({n, 1});
    return pf;
}
int main(){
	int N;
	cin >> N;
	//to precompute all prime numbers with the Sieve of Eratosthenes until n−−√ 
	seive(N);
	//calculate fatorization
	optimized_trial_division(N);
	cout << sqrt(81);
	debug() << imie(pr) imie(pf);
	return 0;
}


