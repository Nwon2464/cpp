#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define imie(...) "["<<#__VA_ARGS__":"<<(__VA_ARGS__)<<"]"
#define sfl(a) scanf("%lld",&a)

const int mod = 1e9+7;

template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
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

const int MAXN = 500;
int ans[MAXN];
 
//class Solution {
//public:
    //void combination(vector<vector<int>>&anss,vector<int>&sub,int target,int i,vector<int>&candidates,int k){
        //if(target==0 && (int)sub.size()==k){
            //anss.push_back(sub);
            //return;
        //}
        //for(int j=i;j<(int)candidates.size();j++){
            //if(target-candidates[j]>=0){
                //sub.push_back(candidates[j]);
                //combination(anss,sub,target-candidates[j],j+1,candidates,k);
                //sub.pop_back();
            //}
                
            
        //}
    //}
    //vector<vector<int>> combinationSum3(int k, int n) {
        //vector<int> candidates;
        //for(int i=1;i<=9;i++){
            //candidates.push_back(i);
        //}
        //vector<vector<int>> anss;
        
        //vector<int> sub;
        //combination(anss,sub,n,0,candidates,k);
        //return ans;
    //}
//};


//void solve() {
    //int n, l, r, s;
    //cin >> n >> l >> r >> s;
    //l--; r--;
    //for (int first = 1; first + (r - l) <= n; first++) {
        //int sum = 0;
        //for (int i = l; i <= r; i++) {
            //sum += first + (i - l);
        //}
        //if (sum <= s && s - sum <= r - l + 1) {
            //int needAdd = r - (s - sum) + 1;
            //vector<int> ans(n);
            //set<int> non_blocked;
            //for (int i = 1; i <= n; i++) {
                //non_blocked.insert(i);
            //}
            //for (int i = l; i <= r; i++) {
                //ans[i] = first + (i - l);
                //if (i >= needAdd) {
                    //ans[i]++;
                //}
                //non_blocked.erase(ans[i]);
            //}
            //if (ans[r] > n) {
                //continue;
            //}
            //non_blocked.erase(ans[r]);
            //for (int i = 0; i < l; i++) {
                //ans[i] = *non_blocked.begin();
                //non_blocked.erase(non_blocked.begin());
            //}
            //for (int i = r + 1; i < n; i++) {
                //ans[i] = *non_blocked.begin();
                //non_blocked.erase(non_blocked.begin());
            //}
            //for (int i : ans) {
                //cout << i << " ";
            //}
            //cout << "\n";
            //return;
        //}
    //}
    //cout << "-1\n";
//}

    



int main()
{
		//solve();
	//(2n+1-k) * k
	
	int t;
    cin >> t;
    while (t--)
    {
	    int n, l, r, s;
        cin >> n >> l >> r >> s;
        int minSum = 0,maxSum = 0;
        for(int i =0;i< r-l+1;i++){
			minSum += i+1;
			maxSum += n - i;
		}
        if(minSum > s || s > maxSum){
			cout << "-1\n";
			continue;
		}
		s -= minSum;
		
		set<int > used;
		for(int i =0;i<r-l+1;i++){
			ans[l+i-1] = i + 1;
		}
		int mx = n;
		for(int i = r-1;i>=l-1;i--){
			
			while(s && ans[i] < mx){
				s--;
				ans[i]++;
			}
			mx = ans[i] - 1;
			used.insert(ans[i]);
		}
		for(int i =0;i < n;i++){
			if(l-1 <= i && i <= r-1 ) continue;
			for(int j =1;j<=n;j++){
			
				if(used.count(j)){
					continue;
				}
				ans[i] = j;
				used.insert(ans[i]);
				break;
			}
			
		}
		cout << "\n";
    }
    return 0;
}


