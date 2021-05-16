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

//Atcoder B job assignment

#include <bits/stdc++.h>

using namespace std;

int t, n;

int main()
{

    cin >> t;
    vector<int> a(t);
    vector<int> b(t);
    for (int i = 0; i < t; i++) {
        cin >> a[i] >> b[i];
    }
    int ans = 100000;
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            ans = min(ans, i == j ? a[i] + b[j] : max(a[i], b[j]));
        }
    }

    cout << ans;
    return 0;
}
