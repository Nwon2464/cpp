#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sfl(a) scanf("%lld", &a)
#define sz(x) (int)(x).size()
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define mp make_pair
#define f first
#define s second
#define pb push_back
const int mod = 1e9 + 7;
template <typename T>
istream& operator>>(istream& is, vector<T>& vec)
{
    for (auto& v : vec)
        is >> v;
    return is;
}
template <typename A, typename B>
istream& operator>>(istream& cin, pair<A, B>& p)
{
    cin >> p.first;
    return cin >> p.second;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec)
{
    os << "[";
    for (auto v : vec)
        os << v << ",";
    os << "]";
    return os;
}
template <typename T_vector>
void output_vector(const T_vector& v, bool add_one = false, int start = -1, int end = -1)
{
    if (start < 0)
        start = 0;
    if (end < 0)
        end = int(v.size());
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}
template <typename T>
ostream& operator<<(ostream& os, const deque<T>& vec)
{
    os << "deq[";
    for (auto v : vec)
        os << v << ",";
    os << "]";
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& vec)
{
    os << "{";
    for (auto v : vec)
        os << v << ",";
    os << "}";
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, const unordered_set<T>& vec)
{
    os << "{";
    for (auto v : vec)
        os << v << ",";
    os << "}";
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& vec)
{
    os << "{";
    for (auto v : vec)
        os << v << ",";
    os << "}";
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, const unordered_multiset<T>& vec)
{
    os << "{";
    for (auto v : vec)
        os << v << ",";
    os << "}";
    return os;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& pa)
{
    os << "(" << pa.first << "," << pa.second << ")";
    return os;
}
template <typename TK, typename TV>
ostream& operator<<(ostream& os, const map<TK, TV>& mp)
{
    os << "{";
    for (auto v : mp)
        os << "(" << v.first << ":" << v.second << ")"
           << ",";
    os << "}";
    return os;
}
template <typename TK, typename TV>
ostream& operator<<(ostream& os, const unordered_map<TK, TV>& mp)
{
    os << "{";
    for (auto v : mp)
        os << v.first << "=>" << v.second << ",";
    os << "}";
    return os;
}
template <typename T>
void ndarray(vector<T>& vec, int len, T init) { vec.assign(len, init); }
template <typename T, typename... Args>
void ndarray(vector<T>& vec, int len, Args... args)
{
    vec.resize(len);
    for (auto& v : vec)
        ndarray(v, args...);
}
template <typename T>
bool bmax_self(T& m, const T q)
{
    if (m < q) {
        m = q;
        return true;
    } else
        return false;
}
template <typename T>
bool bmin_self(T& m, const T q)
{
    if (m > q) {
        m = q;
        return true;
    } else
        return false;
}
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T>
void add_self(T& a, const T b)
{
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}
template <typename T>
void sub_self(T& a, const T b)
{
    a -= b;
    if (a < 0) {
        a += mod;
    }
}
template <typename T>
void max_self(T& a, const T b) { a = max(a, b); }
template <typename T>
void min_self(T& a, const T b) { a = min(a, b); }
priority_queue<int> max_pq;
priority_queue<int, vector<int>, greater<int>> min_pq;
//1s 10^8
//2s 2*10^8
//3s 3*10^8
//100s 10^10
//int main()
//{
//long long n,k;
//cin>>n>>k;
//unsigned long long int count= 2*(n+k);
//int low=1, high=n;
//while(low<=high)
//{
//long long mid= (low+high)/2;
//if(mid*(mid+3)== count)
//{ cout<<(n-mid);
//break;
//}
//if(mid*(mid+3) >count)
//high= mid-1;
//else
//low= mid+1;
//}
//}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), t(n);
    rep(i, 0, n) cin >> a[i];
    int temp = 0;
    rep(i, 0, n)
    {
        temp += a[i];
        a[i] = temp;
    };

    int m;
    cin >> m;
    vector<int> b(n);
    rep(i, 0, m) cin >> b[i];

    for (int i = 0; i < m; i++) {
        auto it = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        cout << it + 1 << "\n";
    }

    return 0;
}
