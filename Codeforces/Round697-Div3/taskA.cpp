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
        int64_t n;
        cin >> n;
        while(n%2==0)
            n/=2;
        cout << (n == 1 ? "NO" : "YES") << "\n";
    }

    return 0;
}
