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
        vector<int> costs(m),arr(n);
        for(int i=0; i<n; i++)
            cin >> arr[i];
        for(int i=0; i<m; i++)
            cin >> costs[i];
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0; i<m; i++)
            pq.push(costs[i]);
        sort(arr.begin(),arr.end());
        vector<int> res(n);
        for(int i=0; i<n; i++)
            res[i] = costs[arr[i]-1];
        for(int i=n-1; ~i; i--) {
            if(pq.top()<res[i]) {
                res[i] = pq.top();
                pq.pop();
            }
        }
        int64_t ans = 0;
        for(int i=0; i<n; i++)
            ans += res[i];
        cout << ans << "\n";
    }

    return 0;
}
