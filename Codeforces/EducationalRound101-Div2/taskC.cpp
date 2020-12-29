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
        int n,k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            cin >> arr[i];
        vector<int> hi(n),lo(n);
        hi[0]=lo[0]=arr[0];
        for(int i=1; i<n; i++) {
            hi[i]=min(hi[i-1]+k-1,arr[i]+k-1);
            lo[i]=max(lo[i-1]-(k-1),arr[i]);
            if(arr[i]+k-1<lo[i] || arr[i]>hi[i]) {
                cout << "NO\n";
                goto end;
            }
        }
        if(arr[n-1]<lo[n-1] || arr[n-1]>hi[n-1]) {
            cout << "NO\n";
            goto end;
        }
        cout << "YES\n";
        end:;
    }

    return 0;
}
