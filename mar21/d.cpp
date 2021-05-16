#include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define ris return *this
#define dor > debug& operator<<
#define eni(x)                                                                   \
    sim > typename enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) \
    {
sim > struct rge {
    c b, e;
};
sim > rge<c> range(c i, c j) { return rge<c> { i, j }; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
    ~debug()
    {
        cerr << "\n";
    }
    eni(!=) cerr << boolalpha << i;
    ris;
} eni(==) ris << range(begin(i), end(i));
}
sim, class b dor(pair<b, c> d)
{
    ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d)
{
    *this << "[";
    for (auto it = d.b; it != d.e; ++it)
        *this << ", " + 2 * (it == d.b) << *it;
    ris << "]";
}
#else
    sim dor(const c&)
    {
        ris;
    }
#endif
}
;
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;

void solve(int p, int a[], int b[], int n, int k)
{
    sort(a, a + n);
    sort(b, b + k);
    int ans = 2 * 0x3f3f3f3f;
    // n = 2  k = 4
    // a[20,100]
    // b[10,40,60,80]
    for (int i = 0; i <= k - n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            int cc = abs(a[j] - b[i + j]) + abs(p - b[i + j]);
            sum = max(sum, abs(a[j] - b[i + j]) + abs(p - b[i + j]));
        }
        ans = min(sum, ans);
    }
    cout << ans << endl;
}
int main()
{
    int n, k, p, a[5], b[5];
    cin >> n >> k >> p;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < k; i++)
        cin >> b[i];
    solve(p, a, b, n, k);
}

// using ll = long long;
// int n, k;
// int main() {
//   cin >> n >> k;
//   vector<int> arr(n);
//   vector<int> brr(n);

//   for (int i = 0; i < n; i++) cin >> arr[i];
//   for (int i = 0; i < n; i++) cin >> brr[i];

//   int prefix[n];
//   int suffix[n];
//   int prefixSum[n];

//   for (int i = 0; i < n; i++) {
//     prefix[i] = arr[i] * brr[i] + (i ? prefix[i - 1] : 0);
//   }
//   int b = 0;

//   for (int i = n - 1; i >= 0; i--) {
//     suffix[i] = arr[i] * brr[i] + (i != n - 1 ? suffix[i + 1] : 0);
//   }
//   int sum = 0;
//   for (int i = 0; i < n; i++) {
//     sum += arr[i];
//     prefixSum[i] = sum;
//   }
//   int ans = 0;

//   for (int i = 0; i + k - 1 < n; i++) {
//     int curr = 0;
//     if (i + k < n) curr += suffix[i + k];
//     if (i > 0) curr += prefix[i - 1];
//     int range_prefix = prefixSum[i + k - 1];
//     if (i > 0) range_prefix -= prefixSum[i - 1];
//     curr += range_prefix;

//     ans = max(ans, curr);
//   }
//   cout << ans << " ";
//--------------------------------------------------------------------------
// int n,k;
// int main() {

// 	cin >> n >> k;
// 	vector<int> arr(n);
// 	vector<int> brr(n);

// 	for(int i=0; i <n;i++)cin >>arr[i];
// 	for(int i=0; i <n;i++)cin >>brr[i];

// 	int p[n];
// 	p[0] = arr[0] * brr[0];

// 	for(int i =1;i<n;i++){
// 		p[i] = arr[i] * brr[i] + p[i-1];
// 	}
// 	int s[n];
// 	int r = 0;
// 	for(int i = n-1; i>=0;i--){
// 		r += arr[i] * brr[i];
// 		s[i] = r;
// 	}
// 	int pref[n];
// 	r = 0;
// 	for(int i =0;i<n;i++){
// 		r += arr[i];
// 		pref[i] = r;
// 	}

// 	int ans = 0;

// 	for(int i =0;i+k-1<n;i++){
// 		int curr = 0;
// 		if(i >0 ) curr += p[i-1];
// 		if(i+k < n) curr+= s[i+k];
// 		int range_sum = pref[i+k-1];
// 		if(i>0) range_sum -= pref[i-1];
// 		curr+= range_sum;

// 		ans = max(ans,curr);

// 	}
// 	cout << ans << "\n";
