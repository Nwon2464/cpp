#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sfl(a) scanf("%lld",&a)
#define sz(x) (int)(x).size()

const int mod = 1e9+7;

template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
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
template<typename T> void add_self(T &a, const T b) {a += b; if(a >= mod) {a -=mod;}}
template<typename T> void sub_self(T &a, const T b) {a -= b; if(a < 0) {a +=mod;}}
template<typename T> void max_self(T &a, const T b) {a = max(a,b);}
template<typename T> void min_self(T &a, const T b) {a = min(a,b);}

priority_queue<int> max_pq;
priority_queue<int, vector<int>, greater<int>> min_pq;

const int nax = 2e5+5;
//ll a[nax],b[nax],dp[nax];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int > a(n);
	rep(i,0,n) cin >> a[i];
	ll ans = 0;
	ll maxi = a[0];
	for(ll i : a){
		maxi = max(i,maxi);
		ans += maxi - i;
	}  
	  cout << ans;
	  
	//for(int i =0 ; i <n-1;i++){
	  //if(a[i] > a[i+1]){
		//ans += a[i] - a[i+1];
	      //a[i+1] = a[i];
		//}
	 //}
  
    //cout << ans << "\n";

	//for(ll i =1;i<=n;i++) cin >> a[i];
	//ll maxi = 0;
	//for(ll i =1;i<=n;i++){
		//while(maxi< a[i]){
			//b[i] = a[i];
			//maxi = a[i];
			//i++;
		//} 
		//b[i] = maxi;
	//}
	//for(ll i =1;i<=n;i++){
		//dp[i] = abs(a[i]-b[i]);
	//}
	//ll sum = 0 ;
	//for(ll x: dp){
		//sum+= x;
	//}
	//cout << sum << "\n";
	return 0;
}
