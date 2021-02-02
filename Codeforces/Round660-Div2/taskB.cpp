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
        int n;
        cin >> n;
        int eights = (n + 3) / 4;
        n -= eights;
        while(n--)
            cout << 9;
        while(eights--)
            cout << 8;
        cout << "\n";
    }

    return 0;
}
