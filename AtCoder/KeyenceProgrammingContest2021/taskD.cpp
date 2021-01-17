#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cout << (1<<n)-1 << "\n";
    for(int i=1; i<=(1<<n)-1; i++) {
        for(int j=0; j<(1<<n); j++)
            cout << (__builtin_popcount(i & (j+1)) % 2 ? 'A' : 'B');
        cout << "\n";
    }

    return 0;
}
