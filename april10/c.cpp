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

void solve()
{
    int x, y;
    string s;
    cin >> x >> y >> s;
    int n = s.length();
    // 01?????0
    // if either s[0] or s[last] is == '?', replace it with 0 or 1
    // based on s[i] or s[n-i-1]
    for (ll i = 0; i < (n + 1) / 2; i++) {
        if (s[i] == '?' || s[n - i - 1] == '?') {
            if (s[i] == '?')
                s[i] = s[n - i - 1];
            if (s[n - i - 1] == '?')
                s[n - i - 1] = s[i];
        }
    }
    // count how many 0 or 1 in the string
    ll ct[2] = { 0 };
    for (char c : s)
        ++ct[c - '0'];

    // if both s[i] and s[n-i-1] are '?' then need to check
    // if occurrences of 0 is less than a we put 0 and count up to 2;
    // or if occurrences of 1 is less than b we put 1 and count up to 2;
    for (ll i = 0; i < (n + 1) / 2; i++) {
        if (s[i] == '?' && s[n - i - 1] == '?') {
            ll cur = 1 + (i != (n - i - 1));

            if (ct[0] + cur <= x) {
                s[i] = s[n - i - 1] = '0';
                ct[0] += cur;
            } else {
                s[i] = s[n - i - 1] = '1';
                ct[1] += cur;
            }
        }
    }

    // check to see if string is palindrome or not
    bool pos = 1;
    for (ll i = 0; i < (n + 1) / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            pos = 0;
        }
    }
    // if occurrences a and b are same as mapped value,
    // return s or -1
    if (ct[0] == x && ct[1] == y && pos) {
        cout << s << '\n';
    } else {
        cout << -1 << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
