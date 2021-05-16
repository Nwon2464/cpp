// Debug, type gdb filename  not filename.out or cpp
// b - main b stands for break
// r - run
// l - Stands for list that will debug for
// f - Defines where the debugger right now
// n - Step over (Does't step into functions)
// s - Step into
// p - Print variable
// bt- Print a stack trace
// c - Continues running the program until the next breakpoint or error
// r - Runs the program until a breakpoint or error

#include <bits/stdc++.h>

using namespace std;

bool checkPalindromePermutation(const string s)
{
    vector<int> ascii(26, 0);
    for (int c : s) {
        if ('a' <= c && c <= 'z') {
            ascii[c - 'a']++;
        } else if ('A' <= c && c <= 'Z') {
            ascii[c - 'A']++;
        }
    }
    int cnt = 0;
    for (int i = 0; i < ascii.size(); i++) {
        if (ascii[i] % 2 == 1) {
            cnt++;
        }
    }
    if (cnt <= 1) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    // string s = "Rats live on no evil star";
    // if (checkPalindromePermutation(s)) {
    //   cout << "YES";
    // } else {
    //   cout << "No";
    // }

    string sieveChars(50, 'P');
    sieveChars.replace(0, 2, "NN");
    for (int i = 2; i <= (sieveChars.size() / 2) - 1; i++) {
        for (int factor = 2; factor * i < sieveChars.size(); factor++) {
            sieveChars[factor * i] = 'N';
        }
    }

    return 0;
}
