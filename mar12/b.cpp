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

int N, A, S, D, X, Y, V, P, t, M, T;

long long x, a;
const int INF = 1e9 + 5;
int main()
{

    // N = Total Capacity, M times visit cafe, T times return home
    // capacity decrease by 1 for 0.5 sec
    // during stay, increase by 1 battery
    cin >> N >> M >> T;
    vector<int> arr(M + 1);

    vector<int> brr(M + 1);

    for (int i = 1; i < M + 1; i++) {
        cin >> arr[i] >> brr[i];
    }
    int n = N;
    string s = "Yes";

    for (int i = 1; i < M + 1; i++) {
        n = n - (arr[i] - brr[i - 1]);
        if (n <= 0) {
            s = "No";
        }
        if (N < n + brr[i] - arr[i]) {
            n = N;
        } else {
            n = n + brr[i] - arr[i];
        }
    }
    n = n - (T - brr[M]);
    if (n <= 0) {
        s = "No";
    }
    cout << s << endl;

    return 0;
}
