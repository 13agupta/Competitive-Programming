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
        set<int> se;
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            cin >> arr[i];
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                se.insert(abs(arr[j]-arr[i]));
            }
        }
        cout << sz(se) << "\n";
    }

    return 0;
}
