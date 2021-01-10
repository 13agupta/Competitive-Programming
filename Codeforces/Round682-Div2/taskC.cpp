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
        int n,m;
        cin >> n >> m;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++)
                cin >> arr[i][j];
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int parity = (i+j)%2;
                if(arr[i][j]%2!=parity)
                    arr[i][j]++;
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++)
                cout << arr[i][j] << " ";
            cout << "\n";
        }
    }

    return 0;
}
