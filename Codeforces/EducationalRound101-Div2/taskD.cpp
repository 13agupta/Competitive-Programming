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
        vector<pair<int,int>> res;
        for(int i=3; i<n; i++) {
            if(i==16) continue;
            res.push_back({i,n});
        }
        int on=n;
        if(n<=16) {
            while(n!=1) {
                res.push_back({on,2});
                n=(n+1)/2;
            }
        }
        else {
            while(n!=1) {
                res.push_back({on,16});
                n=(n+15)/16;
            }
            n=16;
            while(n!=1) {
                res.push_back({16,2});
                n=(n+1)/2;
            }
        }
        cout << sz(res) << "\n";
        for(int i=0; i<sz(res); i++)
            cout << res[i].first << " " << res[i].second << "\n";
    }

    return 0;
}
