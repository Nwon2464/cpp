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
//O(n^2)
//void solve(){
	//string s;
	//cin >> s;
	//int n = s.size(); 
	//vector<int> occur[26];
	//for(int i = n-1;i>=0;i--){
		//occur[s[i]-'a'].push_back(i);
	//}
	//int start = 0;
		
	//while(true){
		//bool isOK = false;
		//for(int use = 25; use>=0;use--){
			//if(!occur[use].empty()){
				//int where = occur[use].back();
				//bool all_present = true;
				//for(int c = 0;c<26;c++){
					//if(!occur[c].empty()){
					   //if(occur[c][0] < where){
							//all_present = false;
							//break;
						//}
					//}
				//}
				//if(all_present){
				   //cout << s[where];
				   //start = where +1;
				   //occur[s[where]-'a'].clear();
				   //for(int c = 0;c<26;c++){
					   //while(!occur[c].empty() && occur[c].back() < start){
						  //occur[c].pop_back();
					  //}
				  //} 
				   //isOK = true;
				   //break;
			   //}
				
			//}
		//}
		//if(!isOK) break;
	//}
	//cout << endl;

	
//}


// O(n)
//void solve(){
	//string s;
	//cin >> s;
	//int n = s.size(); 
	//vector<bool> exists(26);
	//FOR(i,n) exists[s[i] - 'a'] = true;
	//int idx = 0;
		
	//while(true){
		//bool isOK = false;
		//for(int i = 25; i>=0;i--){
			//if(exists[i]){
				//int where = idx;
				//while(s[where]-'a' != i){
					//where++;
				//}
				//vector<bool> suffix(26);
				//for(int j = where;j < n;j++){
				   //if(exists[s[j]-'a']){
						//suffix[s[j]-'a'] = true;
					//}
				//}
				//if(suffix == exists){
				   //cout << s[where];
				   //idx = where + 1;
				   //exists[s[where] - 'a'] = false;
				   //isOK = true;
				   //break;
			   //}
				
			//}
		//}
		//if(!isOK) break;
	//}
	//cout << endl;

//}

// using bitmask
int getUsed(string& s, char &takeFirst){
	int res =0;
	bool seen = false;
	
	for(auto x: s){
		if(x == takeFirst){
			seen = true;
		}
		if(seen){
			res = res | (1 << ( x - 'a'));
		}
	}
	//cout << res << " ";
	return res;
}

int solve() {
	string s;
	cin >> s;
	string ans = "";
	int allChars = getUsed(s,s[0]);
	char takeNow = 'z';
	while(takeNow >= 'a'){
		if(getUsed(s,takeNow) == allChars){
			ans += takeNow;
			int firstIndex = s.find_first_of(takeNow);
			if(firstIndex == -1){
				takeNow--;
				continue;
			}
			s=s.substr(firstIndex);
			int pos = 0;// you can use "size_t" which is unsigend, size_t is 64bits, int(signed) remains 32bits 
			while ((pos = s.find(takeNow)) != (int)string::npos) {
				s.replace(pos, 1, "");
			}
			
			
			
			if(s.empty()){
				break;
			}
			allChars -= 1 << (takeNow - 'a');
			takeNow= 'z' + 1;
		}
		takeNow--;
	}
	cout << ans << "\n";
	
	
	return 0;
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


