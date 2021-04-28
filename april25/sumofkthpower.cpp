#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sfl(a) scanf("%lld",&a)
#define sz(x) (int)(x).size()
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define mp make_pair
#define f first
#define s second
#define pb push_back
//const int mod = 1e9+7;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) { cin >> p.first; return cin >> p.second;}
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << "(" << v.first << ":" << v.second << ")" << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename T> void ndarray(vector<T> &vec, int len, T init) { vec.assign(len, init); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool bmax_self(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool bmin_self(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
//template<typename T> void add_self(T &a, const T b) {a += b; if(a >= mod) {a -=mod;}}
//template<typename T> void sub_self(T &a, const T b) {a -= b; if(a < 0) {a +=mod;}}
template<typename T> void max_self(T &a, const T b) {a = max(a,b);}
template<typename T> void min_self(T &a, const T b) {a = min(a,b);}
const int mod=1e9+7;
const int N=1e6+10;
int n,k,f[N]={1},a[N];
int MOD =  1e9 + 7;
 
int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}
 
int add(int a, int b) {
    int s = (a+b);
    if (s>=MOD) s-=MOD;
    return s;
}
 
int sub(int a, int b) {
    int s = (a+MOD-b);
    if (s>=MOD) s-=MOD;
    return s;
}
 
int po(int a, ll deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}
int inv(int n)
{
    return po(n, MOD-2);
}

int solve(){
	int res=0,s=1;
	for(int i=1;i<=k+2;i++)	{
		f[i]=mul(f[i-1],i);
		s=mul(s,(n-i));
	}
	for(int i=1;i<=k+2;i++){
		int s1=mul(s,inv(n-i));
		int s2=mul(f[i-1],f[k+2-i]);
		if((k+2-i)&1)s2=-s2,s2=(s2+mod)%mod;
		res = add(res,mul(mul(a[i],s1),inv(s2)));
	}
	return res;
}
signed main(){
	cin>>n>>k;
	for(int i=1;i<=k+2&&i<=n;i++){
		a[i]=add(a[i-1],po(i,k));
	}
	if(n<=k+2)	return cout<<a[n],0;
	cout<<solve();
	return 0;
}
