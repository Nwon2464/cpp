#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sfl(a) scanf("%lld", &a)
#define sz(x) (int)(x).size()

const int mod = 1e9 + 7;
template <typename A, typename B>
istream& operator>>(istream& cin, pair<A, B>& p)
{
    cin >> p.first;
    return cin >> p.second;
}
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
const int INF = 1e5 + 5;
const int nax = 5;
string s;
const int dirx[4] = { 0, 0, -1, 1 };
const int diry[4] = { 1, -1, 0, 0 };
int n, m, k;

bool valid(int x, int y)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}
void solve()
{

    cin >> n >> m >> k;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> good(n, vector<int>(m, INF));
    rep(i, 0, n)
    {
        cin >> s;
        rep(j, 0, m)
        {
            grid[i][j] = s[j];
        }
    }
    pair<int, int> p1, p2;
    cin >> p1 >> p2;
    --p1.first;
    --p1.second;
    --p2.first;
    --p2.second;

    queue<pair<int, int>> q;

    good[p1.first][p2.second] = 0;
    q.push(make_pair(p1.first, p1.second));

    while (!q.empty()) {
        pair<int, int> t = q.front();
        q.pop();
        int v = good[t.first][t.second] + 1;
        rep(i, 0, 4)
        {
            pair<int, int> t2 = t;
            rep(j, 0, k)
            {
                t2.first += dirx[i];
                t2.second += diry[i];
                if (!valid(t2.first, t2.second) || grid[t2.first][t2.second] == '#' || good[t2.first][t2.second] < v)
                    break;
                if (good[t2.first][t2.second] > v) {
                    good[t2.first][t2.second] = v;
                    q.push(make_pair(t2.first, t2.second));
                }
            }
        }
    }
    cout << good;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
