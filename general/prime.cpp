#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// PRIME NUMBER - Only having 2 factors (1,itself) == gcd(1,itset) == 1
// i.e)  2  => 1,2,  17 => 1,17
// COMPOSITE NUMBER (to be composite number, you have to have more than 2
// factors) i.e) 24 => 1,2,3,4,6,8,12,24 it has more factors than just 1 and
// itself NEITHER i.e) 1 => it only has 1 factor. to be prime number, it has to
// have 2 factors

// Sieve of Eratosthenes

// Sieve of Eratosthenes is an algorithm for finding all the prime numbers in a
// segment [1;n] using
// -------------------------
// Time Complexity         |
// O(nloglogn) operations. |
// O(n) for space          |
// -------------------------

// int n;
// vector<int> is_prime(n + 1, true); // when declaring int vector global, 10^7
// max size. inside function 10^6 is_prime[0] = is_prime[1] = false; for (int i
// = 2; i <= n; i++) {
//     if (is_prime[i] && (long long)i * i <= n) {
//         for (int j = i * i; j <= n; j += i)
//             is_prime[j] = false;
//     }
// }

// when n = 15 [is_prime:[0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0]]
//---------------------------------------------------------------------------------------------------

// global boolean or vector<char> is bit compression. you can store up to 10^8,
// vector<char> recommend
// const nax = 1e8 + 5;
// vector<char> is_prime(nax, 1); //global
// bool is_prime[nax + 1]; //global

// for (int i = 2; i * i <= nax; i++) {
//     if (is_prime[i]) {
//         for (int j = i * i; j <= nax; j++) {
//             is_prime[j] = 1;
//         }
//     }
// }

// ---------------------------------------------------------------------------------------------------
// Sieve of Eratosthenes Having Linear Time Complexity

// it makes sense to use the described algorithm only until for numbers of order
// 10^7 and not greater.

// const int N = 10000000;
// int lp[N + 1];
// vector<int> pr;

// for (int i = 2; i <= N; ++i) {
//     if (lp[i] == 0) {
//         lp[i] = i;
//         pr.push_back(i);
//     }
//     for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N;
//     ++j)
//         lp[i * pr[j]] = pr[j];
// }

// when n = 15 [pr:[2,3,5,7,11,13]]

// ---------------------------------------------------------------------------------------------------
// prime integer factorization. its okay til O^10

// -------------------
// time complexity   |
// O(√n)             |
// -------------------

vector<long long> trial_division1(long long n)
{
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1) {
        factorization.push_back(n);
    }
    return factorization;
}
// when n = 15 factorization [3,5]
// 15 = 3 * 5 which all prime number

// another way to prime factors more efficinet

void printPrimeFactors(int n)
{
    if (n <= 1)
        return;

    while (n % 2 == 0) {
        cout << 2 << " ";
        n = n / 2;
    }

    while (n % 3 == 0) {
        cout << 3 << " ";
        n = n / 3;
    }

    for (int i = 5; i * i <= n; i = i + 6) {
        while (n % i == 0) {
            cout << i << " ";
            n = n / i;
        }

        while (n % (i + 2) == 0) {
            cout << (i + 2) << " ";
            n = n / (i + 2);
        }
    }

    if (n > 3)
        cout << n << " ";

    cout << endl;
}

int main()
{
    int n = 450;

    printPrimeFactors(n);

    return 0;
}

// -----------------------------------------------------------------------------

// a prime number doesn't have any divisors other than 1 and itself.

// primecheck, prime factors, segmented prime,

// More Efficient (larget value) Primality Test
bool isPrime(int n)
{
    if (n == 1)
        return false;

    if (n == 2 || n == 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

//---------------------------------------------------------------------------------
// segmented prime
// https://www.spoj.com/problems/PRIME1/
// constraints : m and n (1 <= m <= n <= 1000000000, n-m<=100000)
// approach : store n-m possible prime check => calculate n,m => range(1,10)
// [0,1,1,0,1,0,1,....]

vector<bool> segmentedSieve(long long L, long long R)
{
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<bool> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<bool> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

int main()
{
    ll n, m;
    cin >> n >> m;

    auto a = segmentedSieve(n, m);
    ll x = n;
    for (int i = 0; i <= m - n; i++) {
        if (a[i] == 1) {
            cout << x << "\n";
        }
        x++;
    }
}
// test case
// 2
// 1 10  [1,.....10] printing 2,3,5,7,...
// 3 5
//----------------------------------------------------------------------------------

// Fermat primality test
using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod)
{
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool PrimeFermat(ll n, int iter = 5)
{
    // integer range [2 <= N <= 2^63-1] can be AC
    if (n < 4)
        return n == 2 || n == 3;

    for (ll i = 0; i < iter; i++) {
        ll a = 2 + rand() % (n - 3);
        if (binpower(a, n - 1, n) != 1)
            return false;
    }
    return true;
}

//----------------------------------------------------------------------------------

// Miller-Rabin primality test

using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod)
{
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s)
{
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(
    u64 n,
    int iter = 5)
{ // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}
void solve()
{
    ll num;
    cin >> num;
    // if(PrimeFermat(num)){
    if (MillerRabin(num)) {
        cout << "YES\n"
             << endl;
    } else {
        cout << "NO\n"
             << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
