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
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            cin >> arr[i];
        vector<int64_t> pref(n);
        pref[n-1] = arr[n-1];
        multiset<int64_t> se[2];
        se[(n-1)%2].insert(pref[n-1]);
        int64_t total;
        for(int i=n-2; ~i; i--) {
            pref[i] = arr[i] - pref[i+1];
            se[i%2].insert(pref[i]);
        }
        if(*se[0].begin() >= 0 && *se[1].begin() >= 0 && pref[0]==0) {
            cout << "YES\n";
            goto end;
        }
        for(int i=n-1; i>0; i--) {
            if(i!=n-1 && pref[i+1] < 0)
                break;
            total = -arr[i] + arr[i-1];
            total *= 2;
            se[i%2].erase(se[i%2].find(pref[i]));
            if(pref[i] - arr[i] + arr[i-1] < 0)
                continue;
            if(!se[i%2].empty() && *se[i%2].begin() + total < 0)
                continue;
            if(!se[1 - i%2].empty() && *se[1 - i%2].begin() - total < 0)
                continue;
            int64_t end_value = pref[0] + (i%2 == 0 ? total : -total);
            if(end_value != 0)
                continue;
            cout << "YES\n";
            goto end;
        }
        cout << "NO\n";
        end:;
    }

    return 0;
}
