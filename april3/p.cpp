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

int getTotalBits(string &s,char& ch){
	int totalBits = 0;
	bool flag = false;
	
	for(int i =0;i<(int)s.size();i++){
		if(s[i] == ch){
			flag = true;
		}
		if(flag){
			totalBits = totalBits |  1 << (s[i]-'a');
		}
	}
	
	return totalBits;

}


  
int main() {
	
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.size();
		vector<bool> exists(26);
		FOR(i,n)  exists[s[i]-'a'] = true;
		int where = 0;
		while(true){
			bool flag = false;
			for(int use = 25; use>=0;use--){
				if(exists[use]){
					int idx = where;
					while(s[idx]-'a'!= use){
						++idx;
					} 
					vector<bool> vis(26);
					for(int j=idx; j<n; j++){
						if(exists[s[j]-'a']){
							vis[s[j]-'a']= true;
						}
					}
					if(vis == exists){
						cout << s[idx];
						exists[s[idx] -'a'] = false;
						where = idx +1;
						flag = true;
						break;
					}
				}
			}
			if(!flag) break;
		}
		cout << endl;
	}
	
	
	
	
	return 0;
}
