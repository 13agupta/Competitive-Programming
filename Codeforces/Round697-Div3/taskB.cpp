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
        int cnt = 0;
        while(cnt * 2020 <= n) {
            int rem = n - cnt*2020;
            if(rem%2021 == 0) {
                cout << "YES\n";
                goto end;
            }
            cnt++;
        }
        cout << "NO\n";
        end:;
    }

    return 0;
}
