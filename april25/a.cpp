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

// Function for extended Euclidean Algorithm
int extendedgcd(int a, int b, int& x, int& y);

// Function to find modulo inverse of a
void modInverse(int a, int m)
{
    int x, y;
    int g = extendedgcd(a, m, x, y);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else {

        // m is added to handle negative x
        int res = (x % m + m) % m;
        cout << "Modular multiplicative inverse is " << res;
    }
}

// Function for extended Euclidean Algorithm

int extendedgcd(int a, int b, int& x, int& y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extendedgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll binPow(ll a, ll b, ll m)
{
    a %= m;
    ll ans = 1;
    while (b > 0) {
        if (b & 1)
            ans = ans * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}
//slightly worse complexity: O(nlogn)
void phi_1_to_n(int n)
{
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    cout << phi;
}
//O(nloglogn)  identical to the Sieve of Eratosthenes
int phi(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

// Driver Code
int main()
{
    int a = 7, m = 31;

    //phi_1_to_n(21);
    //cout << phi(21) << " ";

    //7x≡1(mod31)

    //Finding the Modular Inverse using Binary Exponentiation using Euler Toient function
    //aϕ(m)≡1 mod m  -- Euler's function,  condition : gcd(a,m) = 1
    //if m is prime, above Euler's theorem can simplifies to Fermat Little Theorem

    //a^m−1≡1 mod m (Fermat Little Theorem)

    //Multiply both sides of the above equations by a−1, and we get
    //For an arbitrary (but coprime) modulus m:  aϕ(m)−1≡a^−1 mod m (Euler) condition : gcd(a,m)==1;
    //For a prime modulus m: a^m−2≡a^−1 mod m  (Fermat) condition : p is prime

    //in case when m is not a prime number, we need to calculate Euler phi function, which involves factorization of m, which might be very hard. If the prime factorization of m is known, then the complexity of this method is O(logm).
    //a^m-2 ≅  a^-1(mod m) (Fermat)  //Inverse(a) means a^-1

    //int phiii = phi(m) -1; // Euler (gcd(a,m) == 1)
    //cout << binPow(a,phiii,m);
    //phi_1_to_n(a);
    //cout << binPow(a,m-2,m) << " ";//Fermat (m is prime) if m is prime above Euler's theorem can simplifies to Fermat Little Theorem

    //---------------------------------------
    //Finding the Modular Inverse using Extended Euclidean algorithm
    //original Extended Euclidean algorithms   a*x + b*y = 1
    //condition :gcd (a,m) == 1 for the modular inverse exists
    // ax + my = gcd(a,m) = 1
    // ax-1= (-y)m
    // a⋅x ≡ 1 mod m
    modInverse(3, 26);
    //----------------------------------

    //Finding the modular inverse for every number modulo m
    //int inv[m];
    //a = 7, m = 31
    // inv[7] is an answer
    //inv[1] = 1;
    //for(int i = 2; i < m; ++i)
    //inv[i] = m - (m/i) * inv[m%i] % m;
    //for(auto x: inv){
    //cout << x << " " ;
    //}

    return 0;
}
