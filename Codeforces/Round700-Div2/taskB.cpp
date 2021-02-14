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
        int64_t a,b,n;
        cin >> a >> b >> n;
        vector<vector<int64_t>> arr(n,vector<int64_t>(2));
        for(int i=0; i<n; i++)
            cin >> arr[i][0];
        for(int i=0; i<n; i++)
            cin >> arr[i][1];
        vector<int> inds(n);
        iota(inds.begin(),inds.end(),0);
        sort(inds.begin(),inds.end(),[&](int a,int b) {
                return arr[a][0] < arr[b][0];
                });
        for(int i=0; i<n; i++) {
            int cur = inds[i];
            if(b <= 0) {
                cout << "NO\n";
                goto end;
            }
            int64_t times = (arr[cur][1] + a - 1) / a;
            b -= arr[cur][0] *  times;
            if(b <= -arr[cur][0]) {
                cout << "NO\n";
                goto end;
            }
        }
        cout << "YES\n";
        end:;
    }

    return 0;
}
