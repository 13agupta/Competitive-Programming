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
        int n,c[2],h;
        cin >> n >> c[0] >> c[1] >> h;
        int cnt[2];
        cnt[0]=cnt[1]=0;
        for(int i=0; i<n; i++) {
            char e;
            cin >> e;
            cnt[e-'0']++;
        }
        cout << min({c[0]*cnt[0] + c[1]*cnt[1],c[0]*cnt[0] + (c[0] + h)*cnt[1],c[1]*cnt[1] + (c[1]+h)*cnt[0]}) << "\n";
    }

    return 0;
}
