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

using u64 = uint64_t;
using u128 = __uint128_t;

ll r, k;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<ll> p;
    //if r= 20,
    //and prime number is not given, instead natural number is given n = 20,
    //you need to find and
    // count the number of integers in the interval [1;r] that are relatively prime to n
    //(their greatest common divisor is 1).
    cin >> r >> k;
    for (int i = 0; i < k; i++) {
        ll x;
        cin >> x;
        p.push_back(x);
    }
    ll sum = 0;
    for (ll msk = 1; msk < (1 << p.size()); ++msk) {
        double mult = 1; // double in used  to prevent from multiplying overflow
        ll bits = 0;
        for (ll i = 0; i < (ll)p.size(); ++i)
            if (msk & (1 << i)) {
                ++bits;
                mult *= p[i]; // ------------------
            } // when you mult *= p[i] since double in used, prevent from overflow
        // when mult *= p[i] with double , it give me scientific value i,e x.xxxxxxe+32
        //24929660627620033 * 16706748220911473 ==> overflow when used ll mult = 1

        ll cur = r / (ll)mult; // typecasting needed to get 0 for ll cur
            // i.e) if you dont typecasting  r / x.xxxxxxxx+30 => x.xxxxxxxxxx+xx
            // if you typecast, r / (ll)mult = 0, bc demoniator is always greater in this case.

        if (bits % 2 == 1) //if bit rem is 1, new subset adding
            sum += cur;
        else // if rem is 0, substracting duplicate subsets
            sum -= cur;
    }
    cout << sum << "\n";
    //cout << r- sum;
    return 0;
}
