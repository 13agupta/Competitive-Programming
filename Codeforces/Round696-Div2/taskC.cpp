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
        vector<int> arr(2*n);
        for(int i=0; i<2*n; i++)
            cin >> arr[i];
        sort(arr.begin(),arr.end());
        for(int i=0; i<2*n-1; i++) {
            deque<pair<int,int>> res;
            multiset<int,greater<int>> se;
            for(int j=0; j<2*n; j++) {
                if(j==i) continue;
                se.insert(arr[j]);
            }
            res.push_back({arr[i],*se.begin()});
            int nxt = *se.begin();
            se.erase(se.begin());
            for(int j=0; j<n-1; j++) {
                int get = nxt;
                nxt = *se.begin();
                se.erase(se.begin());
                // cout << "get: " << get << endl;
                // cout << "nxt: " << nxt << endl;
                if(se.find(get-nxt)==se.end())
                    break;
                res.push_back({nxt,get-nxt});
                se.erase(se.find(get-nxt));
            }
            if(sz(res)==n) {
                cout << "YES\n";
                cout << res[0].first + res[0].second << "\n";
                for(auto &p : res)
                    cout << p.first << " " << p.second << "\n";
                goto end;
            }
        }
        cout << "NO\n";
        end:;
    }
    
    return 0;
}
