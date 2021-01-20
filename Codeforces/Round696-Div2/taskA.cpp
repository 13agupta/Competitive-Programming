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
        string s;
        cin >> s;
        int prev = 1;
        cout << prev;
        for(int i=1; i<n; i++) {
            int tot = s[i-1] - '0' + prev;
            if(s[i]-'0' + 1 != tot) {
                cout << 1;
                prev = 1;
            }
            else {
                cout << 0;
                prev = 0;
            }
        }
        cout << "\n";
    }


    return 0;
}
