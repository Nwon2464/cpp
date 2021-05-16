#include <bits/stdc++.h>

using namespace std;
using ll = long long;
struct UnionFind {
    vector<int> r;
    UnionFind(int N)
    {
        r = vector<int>(N, -1);
    }
    int root(int x)
    { // rooting stage == collapsing find (find min and unite)
        if (r[x] < 0)
            return x; // same as find set
        return r[x] = root(r[x]);
    }
    bool unite(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        if (r[x] > r[y])
            swap(x, y);
        r[x] += r[y];
        r[y] = x;
        return true;
    }
    int size(int x)
    {
        return -r[root(x)];
    }
    //bool find(int x, int y) {
    //return root(x) == root(y);
    //}
};
