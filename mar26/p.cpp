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
#define rep(i,n) for(int i =0; i<(n); i++)

using ll = long long;

int main() {
	bitset<10> bit1,bit2,bit3;
	vector<int> a {5,2,8,9,4};
	vector<int> b{3,2,9,5};
	//Time complexity 
	// O(1) << O(log n) << O(sqrt(n)) << O(n) << O(n log n) << O(n^2)
	// << O(n^3) << O(2^n) << O(n!)
	
	// construct a set of elements that appear in a 
	// iterate through the elements of B and check for each elements
	// this is efficient because the elements of a are in a set
	// using set structure, the time complexity of this algorithms is 
	// O(n log n)
	
	//set<int> st;
	//int cnt = 0;
	//rep(i,(int)a.size()) st.insert(a[i]);
	//rep(i,(int)b.size()) st.count(b[i]) ? cnt++ : 0;
	//cout << cnt;

	// It is not necessary to maintain an ordered set like above
	// we can use unordered_set, in this way, it is more efficient
	// Time Complexity is O(n)
	
	//unordered_set<int> st2;
	//int cnt2 = 0;
	//rep(i,(int)a.size()) st2.insert(a[i]);
	//rep(i,(int)b.size()) st2.count(b[i]) ? cnt2++ : 0;
	//cout << cnt2;
	
	
	
	// Time Complexity of this algorithms is O(n log n) for sorting
	// + O(n) for the rest == O(n log n)
	//int cnt3 = 0;
	//int i = 0;
	//int j = 0;
	//sort(a.begin(),a.end());
	//sort(b.begin(),b.end());
	
	//while(i< (int)a.size() && j < (int)b.size()){
		//if(a[i] == b[j]){
			//cnt3++;
			//i++;
			//j++;
		//}
		//else if(a[i] < b[j]){
			//i++;
		//}else{
			//j++;
		//}
	//}
	//cout << cnt3;
	
    //Time Complexity O(log min(a.size(),b.size())
	//rep(i,(int)a.size()) {
		//bit1.set(a[i]);
	//}
	//int c = 0;
	//rep(i,(int)b.size()) {
		//bit2.set(b[i]);
	//}
	//bit3 = bit1 & bit2;
	//cout << bit3.count();
	
	
	// How to find min and max in an array, also you can find min or max alone
	//auto m1 = minmax_element(a.begin(),a.end());
	//cout << *m1.first << " " << *m1.second;
	
	//array to unorder_set
	int c[] = {1,2,3,4,5};
	unordered_set <int> bb(c,c+5);
	//vector to unorder_set
	unordered_set <int> aa(a.begin(),a.end());
	
	//find intersection
	int aaa =0;
	rep(i,(int)b.size()){
		if(bb.find(b[i]) != bb.end()){
			aaa++;
		}
	}
	cout << aaa;
	
	return 0;
}
