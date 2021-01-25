#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int tt;
    cin >> tt;
    while(tt--) {
        int a,b,k;
        cin >> a >> b >> k;
        map<int,int> am,bm;
        map<pair<int,int>,int> abm;
        vector<pair<int,int>> arr(k);
        for(int i=0; i<k; i++)
            cin >> arr[i].first;
        for(int i=0; i<k; i++) {
            cin >> arr[i].second;
            am[arr[i].first]++;
            bm[arr[i].second]++;
            abm[arr[i]]++;
        }
        int64_t res = 0;
        for(int i=0; i<k; i++)
            res += k - (am[arr[i].first] + bm[arr[i].second] - abm[arr[i]]);
        res /= 2;
        cout << res << "\n";
    }

    return 0;
}
