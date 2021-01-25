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
        vector<string> a(n),b(n);
        for(int i=0; i<n; i++)
            cin >> a[i];
        for(int i=0; i<n; i++)
            cin >> b[i];
        for(int i=0; i<n; i++) {
            if(a[i][0] != b[i][0]) {
                for(int j=0; j<n; j++)
                    a[i][j] = '1'-a[i][j] + '0';
            }
        }
        for(int j=1; j<n; j++) {
            if(a[0][j] != b[0][j]) {
                for(int i=0; i<n; i++)
                    a[i][j] = '1'-a[i][j] + '0';
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(a[i][j] != b[i][j]) {
                    cout << "NO\n";
                    goto end;
                }
            }
        }
        cout << "YES\n";
        end:;
    }

    return 0;
}
