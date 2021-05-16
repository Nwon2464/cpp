//Debug, type gdb filename  not filename.out or cpp
//b - main b stands for break
//r - run
//l - Stands for list that will debug for
//f - Defines where the debugger right now
//n - Step over (Does't step into functions)
//s - Step into
//p - Print variable
//bt- Print a stack trace
//c - Continues running the program until the next breakpoint or error
//r - Runs the program until a breakpoint or error

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll nax = 200000;
ll i, k, m, n, t, a[nax], dp[nax];
ll ans = 0;
char x;
string s;

int main()
{

    cin >> n >> k;
    cin >> s;

    bool type[26] = { 0 };

    for (ll i = 0; i < k; i++) {
        char c;
        cin >> c;
        type[c - 'a'] = 1;
    }
    for (ll i = 0; i < n; i++) {
        type[s[i] - 'a'] ? a[i] = 1 : a[i] = 0;
    }
    for (ll i = 0; i < n; i++) {
        if (a[i] == 0) {
            dp[i + 1] = 0;
        } else {
            dp[i + 1] = dp[i] + 1;
        }
        ans += dp[i + 1];
    }

    cout << ans << "\n";
    return 0;
}
