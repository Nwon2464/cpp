#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main() {
	int h,w,m;
	cin >> h >> w >> m;
	vector<int> a(h+1);
	vector<int> b(w+1);
	set<pair<int,int>> s;
	for(int i=0;i<m;i++){
		int x, y;
		cin >> x >> y;
		 --x;--y;
		 a[x]++;
		 b[y]++;
		 s.insert(make_pair(x,y));
	 }
	 int mx=0 ,my =0;
	 for(int i=0;i<(int)a.size();i++){
		mx = max(mx,a[i]);
	 }
	 for(int i=0;i<(int)b.size();i++){
		my = max(my,b[i]);
	 }
	 vector<int> im;
	 vector<int> jy;
	 for(int i=0;i<(int)a.size();i++){
		if(mx == a[i]) im.push_back(i);
	 }
	 for(int i=0;i<(int)b.size();i++){
		if(my == b[i]) jy.push_back(i);
	 }	
	 int ans = mx + my;
	 
	 for(int i =0; i < (int)im.size();i++){
		 for(int j =0; j < (int)jy.size();j++){
			if(s.count(pair(im[i],jy[j]))) continue;
			cout << ans;
			return 0;
		 }
	 }
	 --ans;
	 cout << ans;
	 
	 
}
