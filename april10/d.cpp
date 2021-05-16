#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define imie(...) "[" << #__VA_ARGS__ ":" << (__VA_ARGS__) << "]"
#define sfl(a) scanf("%lld", &a)

const int mod = 1e9 + 7;

template <typename T>
istream& operator>>(istream& is, vector<T>& vec)
{
    for (auto& v : vec)
        is >> v;
    return is;
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
        os << v.first << "=>" << v.second << ",";
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

ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e+5;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // sum is a[n+1]
    // x is a[n+2]
    // we can know that even if we sort the array
    // sum of the array will be at last index or last index -1
    // we iterate over til n to get sum
    // compare if a[n](last index -1 ) is same as sum
    // then we print out the array til n;
    // if not, we can sure about sum will be at last index
    // add one more value to sum which is a[n];
    // iterate over til n+1 to check to see
    //if sum - a[i..i<n+1] == a[n+1](last index)
    // mark it as -1 and flag boolean to true and break ;
    // if flag was unchanged, it s imposible print -1
    // else print out except -1

    //example 1
    //18 2 2 3 2 9 2
    //2  2 2 2 3 9 18
    //           ^ after sorted, sum of array is largest or largest -1 index

    cin >> n;
    m = n + 2;

    for (ll i = 0; i < m; i++)
        cin >> a[i];
    sort(a, a + m);

    for (ll i = 0; i < n; i++)
        x += a[i];

    if (a[n] == x) {
        for (ll i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        return 0;
    }

    x += a[n];

    bool flag = false;

    for (ll i = 0; i < n + 1; i++) {
        if (x - a[i] == a[n + 1]) {
            flag = true;
            a[i] = -1;
            break;
        }
    }

    if (!flag) {
        cout << -1;
    } else {
        for (ll i = 0; i < n + 1; i++) {
            if (a[i] != -1) {
                cout << a[i] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
