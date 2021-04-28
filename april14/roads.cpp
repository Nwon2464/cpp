#include <bits/stdc++.h>

using namespace std;
using ll = long long;
//#define rep(i, a, b) for(int i = a; i < (b); ++i)
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


#define all(c) (c).begin(), (c).end() 
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
 
#define F first
#define S second
    
const int MAX_N = 1005;
 
int par[MAX_N], raank[MAX_N];
 
void init(int n) {
  for (int i = 0; i < n; i++) {
    par[i] = i;
    raank[i] = 0;
  }
}
 
int root(int x) {
  return par[x] == x ? x : par[x] = root(par[x]);
}
 
void unite(int x, int y) {
  x = root(x);
  y = root(y);
  if (x == y) return;
 
  if (raank[x] < raank[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (raank[x] == raank[y]) raank[x]++;
  }
}
 
 
 
 
//int N;

struct UnionFind {
	vector<int> r;
	UnionFind(int N) {
		r = vector<int>(N, -1);
	}
	int root(int x) { // rooting stage == collapsing find (find min and unite)
		if (r[x] < 0) return x; // same as find set
		return r[x] = root(r[x]);
	}
	bool unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) return false;
		if (r[x] > r[y]) swap(x, y);
		r[x] += r[y];
		r[y] = x;
		return true;
	}
	int size(int x) {
		return -r[root(x)];
	}
	//bool find(int x, int y) {
		//return root(x) == root(y);
	//}
	
};
 
 
int main() {
	int N;
	cin >> N;
	UnionFind uf(N+1);
	vector<pair<int, int> > cls;
    rep(i,N-1) {
		int a, b;
		cin >> a >> b;
		--a;--b;
		if(!uf.unite(a,b)) cls.pb(mp(a,b)); //found a cycle
		else{
			uf.unite(a,b);
		}
	}
	vector<pair<int, int> > bui;
    for(int i =0;i<N;i++){
		for(int j=0;j<i;j++){
		  if (!uf.unite(j,i)) {
			bui.pb(mp(j, i));
			uf.unite(j, i);
		  }
	  }
    }
    printf("%d\n", (int)cls.size());
    rep (i, cls.size()) {
      printf("%d %d %d %d\n", cls[i].F + 1, cls[i].S + 1, bui[i].F + 1, bui[i].S + 1);
    }
  //}
  
  return 0;
}
 


