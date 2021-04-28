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

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}

	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};
namespace number_theory {
	ll gcd(ll x, ll y) {
	  if (x == 0) return y;
	  if (y == 0) return x;
	  return gcd(y, x % y);
	}
	bool isprime(ll n) { 
	  if (n <= 1) return false; 
	  if (n <= 3) return true; 
	  
	  if (n % 2 == 0 || n % 3 == 0) return false; 
	  
	  for (ll i = 5; i * i <= n; i += 6) 
		if (n % i == 0 || n % (i+2) == 0) 
		  return false; 
	  
	  return true; 
	} 
	 
	bool prime[15000105]; 
	void sieve(int n) { 
	  for (ll i = 0; i <= n; i++) prime[i] = 1;
	  for (ll p = 2; p * p <= n; p++) { 
		if (prime[p] == true) { 
		  for (ll i = p * p; i <= n; i += p) 
			prime[i] = false; 
		} 
	  } 
	  prime[1] = prime[0] = 0;
	} 
	 
	vector<ll> primelist;
	bool __primes_generated__ = 0;
	 
	void genprimes(int n) {
	  __primes_generated__ = 1;
	  sieve(n + 1);
	  for (ll i = 2; i <= n; i++) if (prime[i]) primelist.push_back(i);
	}
	 
}

using namespace number_theory;

void solve(){
	typedef number_theory::gcd<1,5> t1;
	
	//.gcd(3,4);

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	
}
