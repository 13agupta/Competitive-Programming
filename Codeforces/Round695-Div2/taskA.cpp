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
            cout << 9 << "\n";
            continue;
        }
        if(n==2) {
            cout << 98 << "\n";
            continue;
        }
        cout << 98;
        int cur = 9;
        n -= 2;
        while(n--) {
            cout << cur;
            cur = (cur+1)%10;
        }
        cout << "\n";
    }

    return 0;
}
