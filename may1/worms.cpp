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
const int mod = 1e9+7;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) { cin >> p.first; return cin >> p.second;}
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T_vector>void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) { if (start < 0) start = 0; if (end < 0) end = int(v.size()); for (int i = start; i < end; i++) cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');}
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
map<int,vector<pair<int,int>>>p;
//g[u].push_back({v,w});
//g[v].push_back({u,w});
//v = g[u][i].first;
const int nax = 1e6+5;
int a[nax];
int n,m,q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int x = 1,y = 0;
	//2 7 3 4 9
	for(int i = 1; i <=n;i++){
		int temp1;
		cin >> temp1;
		y += temp1;
		p[i].push_back({x,y});
		x += temp1;
	};
	
	cin >> q;
	for(int i = 0; i < q;i++){
		cin >> a[i];
	}
	for(int i = 0; i < q;i++){	
		for(auto v : p){
			if(v.s[0].f <=a[i] && a[i] <= v.s[0].s){
				cout << v.f << "\n";
				break;
				
			}
		}
	}
	
	
    return 0;
}



			



