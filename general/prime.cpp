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
//         for (int j = i * i; j <= nax; j+=i) {
//             is_prime[j] = 0;
//         }
//     }
// }

// ---------------------------------------------------------------------------------------------------
// Sieve of Eratosthenes Having Linear Time Complexity

// it makes sense to use the described algorithm only until for numbers of order
// 10^7 and not greater. N should be 10^14 -> sqrt(10^14) = 10^7

const int nax = 1e5; //check what is maximum sqrt(N) ? seive max = 10000000
vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;

void sieve() {
     assert(nax >= 1);
     smallest_factor.assign(nax + 1, 0);
     prime.assign(nax + 1, true);
     prime[0] = prime[1] = false;
     primes = {};

     for (int p = 2; p <= nax; p++)
          if (prime[p]) {
               smallest_factor[p] = p;
               primes.push_back(p);

               for (ll i = ll(p) * p; i <= nax; i += p)
                    if (prime[i]) {
                         prime[i] = false;
                         smallest_factor[i] = p;
                    }
          }
}

vector<pair<ll, int>> prime_factorize(ll n) {
     ll sieve_max = ll(smallest_factor.size()) - 1;
     assert(1 <= n && n <= sieve_max * sieve_max);
     vector<pair<ll, int>> result;
     if (n <= sieve_max) {
          while (n != 1) {
               ll p = smallest_factor[n];
               int exponent = 0;
               while (n % p == 0) {
                    n /= p;
                    exponent++;
               }
               result.emplace_back(p, exponent);
          }
          return result;
     }

     for (ll p : primes) {
          if (p * p > n)
               break;
          if (n % p == 0) {
               result.emplace_back(p, 0);

               while (n % p == 0) {
                    n /= p;
                    result.back().second++;
               }
          }
     }

     if (n > 1)
          result.emplace_back(n, 1);

     return result;
}

// ---------------------------------------------------------------------------------------------------
// prime integer factorization. its okay til O^10

// -------------------
// time complexity   |
// O(√n)             |
// -------------------

vector<long long> trial_division1(long long n) {
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

//----------------------------------------------------------------
// another way to prime factors (printing version)

void printPrimeFactors(int n) {
     if (n <= 1) return;

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

     if (n > 3) cout << n << " ";

     cout << endl;
}

int main() {
     int n = 450;

     printPrimeFactors(n);

     return 0;
}

// -----------------------------------------------------------------------------

//segmented prime,

//---------------------------------------------------------------------------------
// segmented prime
// https://www.spoj.com/problems/PRIME1/
// constraints : m and n (1 <= m <= n <= 1000000000, n-m<=100000)
// approach : store n-m possible prime check => calculate n,m => range(1,10)
// [0,1,1,0,1,0,1,....]

vector<bool> segmentedSieve(long long L, long long R) {
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
     if (L == 1) isPrime[0] = false;
     return isPrime;
}

int main() {
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

u64 binpower(u64 base, u64 e, u64 mod) {
     u64 result = 1;
     base %= mod;
     while (e) {
          if (e & 1) result = (u128)result * base % mod;
          base = (u128)base * base % mod;
          e >>= 1;
     }
     return result;
}

bool PrimeFermat(ll n, int iter = 5) {
     // integer range [2 <= N <= 2^63-1] can be AC
     if (n < 4) return n == 2 || n == 3;

     for (ll i = 0; i < iter; i++) {
          ll a = 2 + rand() % (n - 3);
          if (binpower(a, n - 1, n) != 1) return false;
     }
     return true;
}

//----------------------------------------------------------------------------------

// Miller-Rabin primality test

unsigned mod_pow(unsigned a, unsigned b, unsigned mod) {
     unsigned result = 1;

     while (b > 0) {
          if (b & 1)
               result = unsigned(uint64_t(result) * a % mod);

          a = unsigned(uint64_t(a) * a % mod);
          b >>= 1;
     }

     return result;
}

bool miller_rabin(unsigned n) {
     if (n < 2)
          return false;

     // Check small primes.
     for (unsigned p : { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 })
          if (n % p == 0)
               return n == p;

     int r = __builtin_ctz(n - 1);
     unsigned d = (n - 1) >> r;

     // https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test#Testing_against_small_sets_of_bases
     for (unsigned a : { 2, 7, 61 }) {
          unsigned x = mod_pow(a % n, d, n);

          if (x <= 1 || x == n - 1)
               continue;

          for (int i = 0; i < r - 1 && x != n - 1; i++)
               x = unsigned(uint64_t(x) * x % n);

          if (x != n - 1)
               return false;
     }

     return true;
}

ll get_exponent(ll n) {

     ll sum = 0;

     for (ll p : primes) {
          if (p * p * p > n) //if cube of p > n break to use miller rabin test below;
               break;

          while (n % p == 0) {
               n /= p;
               sum++;
          }
     }

     if (n > 1) {
          cout << "YES"
               << " " << n << endl;
          sum += miller_rabin(n) ? 1 : 2; // if it is prime +1 if not +2
     } //suppose 18.  2 *    9 < not prime +2

     return sum;
}
