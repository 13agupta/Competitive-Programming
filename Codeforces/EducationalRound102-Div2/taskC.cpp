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
        int n,k;
        cin >> n >> k;
        int end = k-(n-k);
        for(int i=1; i<end; i++)
            cout << i << " ";
        for(int j=k; j>=end; j--)
            cout << j << " ";
        cout << "\n";
    }

    return 0;
}
