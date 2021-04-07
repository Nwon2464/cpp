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
#define rep(i,n) for (int i = 0; i < (n); ++i)


using ll = long long;


//Bob wants to play another game!
//You start by giving him 2 positive integers A and B from 1 to 1000. 
//In one turn, he can either double A and add one to B or double B and add one to A.
//Here's an example sequence of steps that he could take:
//(0, 1) => (1, 2) => (2, 3) => (4, 4) => (8, 5)
//You want to prevent him from making A and B equal.
//Choose A and B for him so that he will lose no matter what!

//Highlight at most 7 cells so that all unhighlighted cells are next to a highlighted cell
//5 x 5
 //0 0 0 0 0 
 //0 X 0 X 0 
 //X 0 X 0 X
 //0 X 0 X 0
 //0 0 0 0 0

int main(){
	vector<vector<int>> a(5,vector<int>(5));
	
	for(int i =1 ;i<=1000;i++){
		for(int j = 1;j<=1000;j++){
			if(i == j) cout << i << "equal " << j;
			
			int x = i * i + j +1;
			int y = j * j + i +1;
			if(i != j && x == y) cout << i << j; 
			//cout << x << " " << y ;
			//if(i * i + j+1 == j) cout<< i << " "<< j;
			//if(j * j + i+1 == i)cout << i << " " << j;
		//if(i )
	}
}
	return 0;
}

