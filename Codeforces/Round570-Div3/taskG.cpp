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
        vector<pair<int,int>> cnt(n,{0,0});
        for(int i=0; i<n; i++) {
            int a,f;
            cin >> a >> f;
            a--;
            cnt[a].first++;
            cnt[a].second+=f;
        }
        sort(cnt.begin(),cnt.end());
        priority_queue<int> pq;
        int cur=n-1;
        int tot=0,best=0;
        for(int i=n; i; i--) {
            while(cur>=0 && cnt[cur].first>=i) {
                pq.push(cnt[cur].second);
                cur--;
            }
            if(!pq.empty()) {
                tot+=i;
                best+=min(i,pq.top());
                pq.pop();
            }
        }
        cout << tot << " " << best << "\n";
    }

    return 0;
}
