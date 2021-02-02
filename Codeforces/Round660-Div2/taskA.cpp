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
        if(n <= 30) {
            cout << "NO\n";
        }
        else if(n == 36) {
            cout << "YES\n";
            cout << "6 10 15 5\n";
        }
        else if(n == 40) {
            cout << "YES\n";
            cout << "6 10 15 9\n";
        }
        else if(n == 44) {
            cout << "YES\n";
            cout << "6 10 15 13\n";
        }
        else
        {
            cout << "YES\n";
            cout << "6 10 14 " << n - 30 << "\n";
        }
    }

    return 0;
}
