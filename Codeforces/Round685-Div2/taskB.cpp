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
        int n,q;
        cin >> n >> q;
        string s;
        cin >> s;
        while(q--) {
            int l,r;
            cin >> l >> r;
            l--; r--;
            for(int i=0; i<l; i++) {
                if(s[i]==s[l]) {
                    cout << "YES\n";
                    goto end;
                }
            }
            for(int i=r+1; i<n; i++) {
                if(s[i]==s[r]) {
                    cout << "YES\n";
                    goto end;
                }
            }
            cout << "NO\n";
            end:;
        }
    }

    return 0;
}
