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
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            cin >> arr[i];
        int bmn=0;
        for(int i=1; i<n; i++) {
            if(bmn>arr[i]) {
                cout << "NO\n";
                goto end;
            }
            bmn=max(bmn,arr[i]-(arr[i-1]-bmn));
        }
        cout << "YES\n";
        end:;
    }

    return 0;
}
