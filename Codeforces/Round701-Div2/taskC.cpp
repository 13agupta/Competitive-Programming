#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        int64_t x,y;
        cin >> x >> y;
        int64_t res = 0;
        for(int64_t c=1; c*c<=x; c++) {
            int64_t from = c + 1;
            int64_t fb = y;
            int64_t sb = (x - c) / c;
            int64_t b = min(fb,sb);
            if(b >= from)
                res += b - from + 1;
        }
        cout << res << "\n";
    }

    return 0;
}
