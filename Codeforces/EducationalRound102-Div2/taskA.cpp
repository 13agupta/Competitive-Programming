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
        int n,d;
        cin >> n >> d;
        vector<int> arr(n);
        bool good = true;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
            if(arr[i]>d)
                good = false;
        }
        if(good) {
            cout << "YES\n";
            goto end;
        }
        sort(arr.begin(),arr.end());
        if(n>2 && arr[0]+arr[1]<=d) {
            cout << "YES\n";
            goto end;
        }
        cout << "NO\n";
        end:;
    }

    return 0;
}
