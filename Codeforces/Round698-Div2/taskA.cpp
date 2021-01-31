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
        map<int,int> freq;
        int n;
        cin >> n;
        for(int i=0; i<n; i++) {
            int e; cin >> e;
            freq[e]++;
        }
        pair<int,int> best = {-1,-1};
        for(auto p : freq) {
            if(best.second < p.second)
                best = p;
        }
        cout << best.second << "\n";
    }

    return 0;
}
