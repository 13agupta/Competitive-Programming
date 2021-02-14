#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
const int VAL = int(720720);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;
    vector<vector<int>> arr(n,vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
            cin >> arr[i][j];
    }
    vector<vector<int>> res(n,vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if((i + j) % 2 == 0)
                res[i][j] = VAL;
            else
                res[i][j] = VAL + arr[i][j] * arr[i][j] * arr[i][j] * arr[i][j];
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
