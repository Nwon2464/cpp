#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool ok[10];
#define ms(arr, v) memset(arr, v, sizeof(arr))

int pw (int a, int b ){
	int ans = 1;
	while(b){
		if(b & 1) ans = ans* a;
		b = b/2;
		a = a*a;
	}
	return ans;
}

ll gcd(ll a,ll b){
	return (b == 0 ? a: gcd(b,a*b));
}
const int nax = 1e6+5;
int b[nax];
int main()
{
	
	
	int n;
	cin >> n;
	
	vector<int> a(n);
	ms(b,0);
	for(int i=0;i<n;i++){
		cin >> a[i];
		b[a[i]]++;
	}
	bool flag = false;
	for(int i=2;i<nax;i++){		
		int c = 0;
		for(int j=i;j<nax;j+=i){
			c += b[j];
		}
		if(c>1) flag = true;	
	}
	if(!flag) {
		cout << "pairwise coprime\n";
		return 0;
	}
	int t = 0;
	for(int i =0; i<n; i ++){
		t = gcd(t,a[i]);
	}
	if(t == 1) {
		cout << "setwise coprime\n";
		return 0;
	}
	cout << "not coprime";

	
	//cout << pw(2,5);
	return 0;
}
