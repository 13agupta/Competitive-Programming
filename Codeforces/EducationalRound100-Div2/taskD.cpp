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
        vector<int> arr[2];
        arr[0].assign(n,0);
        arr[1].assign(n,0);
        set<int> se;
        for(int i=0; i<n; i++) {
            cin >> arr[0][i];
            se.insert(arr[0][i]);
        }
        int ind=0;
        for(int i=1; i<=2*n; i++) {
            if(se.find(i)==se.end())
                arr[1][ind++]=i;
        }
        ind=0;
        int best[2];
        best[0]=best[1]=n;
        for(int i=0; i<n; i++) {
            while(ind!=n && arr[1][ind]<arr[0][i]) ind++;
            best[0]=min(best[0],i+n-ind);
        }
        ind=0;
        for(int i=0; i<n; i++) {
            while(ind!=n && arr[0][ind]<arr[1][i]) ind++;
            best[1]=min(best[1],i+n-ind);
        }
        cout << best[0]-(n-best[1])+1 << "\n";
    }

    return 0;
}
