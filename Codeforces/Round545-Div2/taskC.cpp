#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
const int mxN = int(1e3) + 5;
int arr[mxN][mxN];
int east[mxN][mxN],mx_east[mxN],south[mxN][mxN],mx_south[mxN];
int n,m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
            cin >> arr[i][j];
    }
    for(int i=0; i<n; i++) {
        vector<int> cur;
        for(int j=0; j<m; j++)
            cur.push_back(arr[i][j]);
        sort(cur.begin(),cur.end());
        cur.erase(unique(cur.begin(),cur.end()),cur.end());
        mx_east[i] = sz(cur);
        for(int j=0; j<m; j++) {
            auto it = lower_bound(cur.begin(),cur.end(),arr[i][j]);
            east[i][j] = distance(cur.begin(),it) + 1;
        }
    }
    for(int j=0; j<m; j++) {
        vector<int> cur;
        for(int i=0; i<n; i++)
            cur.push_back(arr[i][j]);
        sort(cur.begin(),cur.end());
        cur.erase(unique(cur.begin(),cur.end()),cur.end());
        mx_south[j] = sz(cur);
        for(int i=0; i<n; i++) {
            auto it = lower_bound(cur.begin(),cur.end(),arr[i][j]);
            south[i][j] = distance(cur.begin(),it) + 1;
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int result = max({mx_east[i],mx_south[j],east[i][j] + mx_south[j] - south[i][j],south[i][j] + mx_east[i] - east[i][j]});
            cout << result << " ";
        }
        cout << "\n";
    }

    return 0;
}
