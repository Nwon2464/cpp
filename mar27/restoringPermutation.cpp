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

int main() {
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.length();
		vector<bool> exists(26);
		//vector<int>first(26);
		for(int i =0;i<n;++i){
			int x = s[i] - 'a';
			exists[x] = true;
		}
		int start = 0;
		while(true){
			bool anything = false;
			for(int use= 25;use>=0 ;--use){
				if(exists[use]){
					int where = start;
					while(s[where] - 'a' !=use){
						where++;
					}
					vector<bool> in_suffix(26);
					for(int i=where;i<n;++i){
						if(exists[s[i]-'a']){	
							in_suffix[s[i]-'a'] = true;
						}
					}
					if(in_suffix == exists){
						cout << s[where];
						exists[s[where]-'a'] = false;
						start  = where+1;
						anything = true;
						break;
					}
				}
				//assert(use !=0);
			}
			if(!anything){
				break;
			}
		}
		//puts("");
		cout << "\n";
	}
}

