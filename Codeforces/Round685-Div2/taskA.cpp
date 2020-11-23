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
        if(n==1) {
            cout << 0 << "\n";
        }
        else if(n==2) {
            cout << 1 << "\n";
        }
        else if(n==3) {
            cout << 2 << "\n";
        }
        else if(n%2==0) {
            cout << 2 << "\n";
        }
        else
            cout << 3 << "\n";
    }

    return 0;
}
