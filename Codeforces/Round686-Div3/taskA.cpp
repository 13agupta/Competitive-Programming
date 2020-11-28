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
        int n;
        cin >> n;
        for(int i=n; i>(n+1)/2; i--)
            cout << i << " ";
        for(int i=1; i<=(n+1)/2; i++)
            cout << i << " ";
        cout << "\n";
    }

    return 0;
}
