#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        int n,x;
        cin >> n >> x;
        int64_t tot = 0;
        int64_t beauty = 0;
        for(int i=0; i<n; i++) {
            int e;
            cin >> e;
            tot += e;
            beauty += (e + x-1)/x;
        }
        cout << (tot+x-1)/x << " " << beauty << "\n";
    }

    return 0;
}
