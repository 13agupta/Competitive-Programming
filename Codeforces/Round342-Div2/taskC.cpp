#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin >> n >> k;
    vector<vector<int>> arr(n,vector<int>(n));
    priority_queue<int,vector<int>,less<int>> pq;
    for(int i=1; i<=n*n; i++)
        pq.push(i);
    set<int> used;
    int res = 0;
    for(int i=n-1; i>=0; i--) {
        for(int j=n-1; j>=k-1; j--) {
            arr[i][j] = pq.top();
            used.insert(arr[i][j]);
            pq.pop();
            if(j+1==k)
                res += arr[i][j];
        }
    }
    for(int i=n-1; i>=0; i--) {
        for(int j=k-2; j>=0; j--) {
            arr[i][j] = pq.top();
            pq.pop();
        }
    }
    cout << res << "\n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
    
    return 0;
}
