#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int64_t k,l,r,t,x,y;
    cin >> k >> l >> r >> t >> x >> y;
    if(y < x) {
        if(k + y <= r)
            k += y;
        k -= x;
        int64_t times = (k - l) / (x - y) + 1;
        cout << (t > times || k < l ? "No" : "Yes") << "\n";
    }
    else {
        assert(y >= x);
        for(int64_t iter=0; iter<=x; iter++) {
            int64_t take = (k - l) / x;
            if(t <= take) {
                cout << "Yes\n";
                return 0;
            }
            t -= take;
            k -= take * x;
            k += y;
            if(k > r) {
                cout << "No\n";
                return 0;
            }
        }
        cout << "Yes\n";
    }

    return 0;
}
