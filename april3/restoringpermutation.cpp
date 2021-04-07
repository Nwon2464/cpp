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


//void maximal(vector<int>& a,int n,vector<bool> exists2){
	//int where = 0;
	//for(int use = 0 ; use<=n;use++){
		//if(exists2[use]){
			//int idx = where;
			//while(a[idx] != use){
				//idx++;
			//}
			//int target = a[idx];
			
			//while(a[++idx] <= use){
				//if(exists2[target]){						
					//for(int k = target; k>0;k--){
						//if(!exists2[k]){		
							//exists2[k] = true;
							//a[idx] = k;
							//break;
						//}
					//}
					
				//}	
			//}	
		//}
	//}			
//}
//void minimal(vector<int> a,int n,vector<bool> exists){
	
	//int where = 0;
	//for(int use = 0 ; use<=n;use++){
		//if(exists[use]){
			//find occurrence
			//int idx = where;
			//while(a[idx] != use){
				//idx++;
			//}
			//int target = a[idx];
			
			//while(a[++idx] <= use){
				//if(exists[target]){						
					//for(int k = 1; k<target;k++){
						//if(!exists[k]){		
							//exists[k] = true;
							//a[idx] = k;
							//break;
						//}
					//}
					
				//}
				
			//}	
		//}
	//}
	//for(auto x: a){
		//cout << x << " ";
	//}
	//cout << endl;
		

//}
//void solve(){
	//int n;
	//cin >> n;
	
	//vector<int> a(n);
	//vector<int> b(n);
	
	//vector<bool> exists(n+1);	
	//vector<bool> exists2(n+1);

	//for(int i =0;i< n;i++){
		//int x;
		//cin >> x;
		//a[i] = x;
		//b[i] = x;
		//exists[x] = true;
		//exists2[x] = true;
	//}
	//minimal(b,n,exists2);
	//maximal(a,n,exists);
	
//}

void solve(){
	int n;
		cin >> n;
		vector<int> a(n);
		
		FOR(i,n) cin >> a[i];
		
		priority_queue<int> max_pq;
		priority_queue<int, vector<int>, greater<int>> min_pq;
		//3 3 4 4 7 7 7
		
		vector<int> maxAns(n);
		vector<int> minAns(n);
		
		int seen = 0;
		
		for(int i =0;i< n;i++){
			bool flag = seen != a[i];
			while(seen + 1 < a[i]){
				++seen;
				max_pq.push(seen);
				min_pq.push(seen);
			}
			seen = a[i];
			if(flag){
				minAns[i] = a[i];
				maxAns[i] = a[i];
			}
			else{
				int maxVal = max_pq.top();
				int minVal = min_pq.top();
				min_pq.pop();
				max_pq.pop();
				minAns[i] = minVal;
				maxAns[i] = maxVal;
			}
		}	 
		
		for(auto x : minAns){
			cout << x << " ";
		}
		cout << endl;
		for(auto x : maxAns){
			cout << x << " ";
		}
		cout << endl;
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
		
	return 0;
}
