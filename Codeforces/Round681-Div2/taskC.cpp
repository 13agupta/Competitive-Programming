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
        vector<int> a(n),b(n);
        for(int i=0; i<n; i++)
            cin >> a[i];
        for(int i=0; i<n; i++)
            cin >> b[i];
        map<ll,ll> cnt;
        for(int i=0; i<n; i++) {
            cnt[a[i]]+=b[i];
        }
        vector<pair<ll,ll>> arr;
        for(auto p : cnt)
            arr.push_back(p);
        sort(arr.begin(),arr.end());
        ll cur=0;
        ll best=1e17;
        for(int i=sz(arr)-1; ~i; i--) {
            best=min(best,max(cur,arr[i].first));
            cur+=arr[i].second;
        }
        cout << min(cur,best) << "\n";
    }

    return 0;
}
