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
        vector<int> b(n);
        for(int i=0; i<n; i++) {
            int p=floor(log2(arr[i]));
            b[i]=(1<<p);
        }
        for(int i=0; i<n; i++)
            cout << b[i] << " ";
        cout << "\n";
    }

    return 0;
}
