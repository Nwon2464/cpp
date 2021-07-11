#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

int h, w;
char c[12][12];

int main() {
     scanf("%d%d", &h, &w);
     for (int i = 0; i < h; i++) {
          scanf("\n");
          for (int j = 0; j < w; j++) {
               scanf("%c", &c[i][j]);
          }
     }

     int ret = 0;
     for (int i = 0; i + 1 < h; i++) {
          for (int j = 0; j + 1 < w; j++) {
               int cnt = 0;
               if (c[i][j] == '#') cnt++;
               if (c[i][j + 1] == '#') cnt++;
               if (c[i + 1][j] == '#') cnt++;
               if (c[i + 1][j + 1] == '#') cnt++;
               if (cnt % 2 == 1) ret++;
          }
     }
     cout << ret << endl;
}
