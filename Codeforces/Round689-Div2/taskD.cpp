#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
int n,q;
vector<int64_t> arr,pref;

void check(set<int64_t> &valid,int l,int r) {
    if(l < 0 || r >= n || l > r) return;
    valid.insert(pref[r+1] - pref[l]);
    if(arr[l] == arr[r])
        return;
    int64_t value = (arr[l] + arr[r]) / 2;
    auto it = upper_bound(arr.begin(),arr.end(),value);
    --it;
    int p = distance(arr.begin(),it);
    check(valid,l,p);
    check(valid,p+1,r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        cin >> n >> q;
        arr.assign(n,0);
        for(int i=0; i<n; i++)
            cin >> arr[i];
        sort(arr.begin(),arr.end());
        pref.assign(n+1,0);
        pref[0] = 0;
        for(int i=1; i<n+1; i++)
            pref[i] = pref[i-1] + arr[i-1];
        set<int64_t> valid;
        check(valid,0,n-1);
        while(q--) {
            int sum;
            cin >> sum;
            if(valid.find(sum) != valid.end())
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }

    return 0;
}
