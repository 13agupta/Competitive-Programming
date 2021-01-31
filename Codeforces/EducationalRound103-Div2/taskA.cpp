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
        int64_t n,k;
        cin >> n >> k;
        k = ((n + k-1) / k) * k;
        cout << (k + n-1) / n << "\n";
    }

    return 0;
}
