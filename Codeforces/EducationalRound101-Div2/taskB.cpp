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
        vector<int> r(n);
        for(int i=0; i<n; i++)
            cin >> r[i];
        int m;
        cin >> m;
        vector<int> b(m);
        for(int i=0; i<m; i++)
            cin >> b[i];
        int cur[2];
        cur[0]=cur[1]=0;
        int best[2];
        best[0]=best[1]=0;
        for(int i=0; i<n; i++) {
            cur[0]+=r[i];
            best[0]=max(best[0],cur[0]);
        }
        for(int i=0; i<m; i++) {
            cur[1]+=b[i];
            best[1]=max(best[1],cur[1]);
        }
        cout << best[0]+best[1] << "\n";
    }

    return 0;
}
