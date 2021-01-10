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
        sort(arr.begin(),arr.end());
        for(int i=1; i<n; i++) {
            if(arr[i]==arr[i-1]) {
                cout << "YES\n";
                goto end;
            }
        }
        cout << "NO\n";
        end:;
    }

    return 0;
}
