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
        vector<int> deg(n,0);
        for(int i=0; i<n-1; i++) {
            int u,v;
            cin >> u >> v;
            u--; v--;
            deg[u]++;
            deg[v]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> pq;
        int64_t value=0;
        for(int i=0; i<n; i++) {
            deg[i]--;
            value+=arr[i];
            if(deg[i])
                pq.emplace(arr[i],deg[i]);
        }
        cout << value << " ";
        for(int i=1; i<n-1; i++) {
            pair<int,int> cur=pq.top(); pq.pop();
            value+=cur.first;
            cur.second--;
            if(cur.second)
                pq.push(cur);
            cout << value << " ";
        }
        cout << "\n";
    }

    return 0;
}
