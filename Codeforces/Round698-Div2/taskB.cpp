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
        int q,d;
        cin >> q >> d;
        int greater = d * 10;
        vector<bool> dp(2*greater,false);
        int start = d;
        vector<int> transitions;
        while(start < greater) {
            transitions.push_back(start);
            start += 10;
        }
        dp[0] = true;
        for(int i=0; i<greater; i++) {
            for(auto transition : transitions)
                dp[i + transition] = (dp[i] || dp[i + transition]);
        }
        for(int i=0; i<q; i++) {
            int e; cin >> e;
            if(e >= greater)
                cout << "YES\n";
            else
                cout << (dp[e] ? "YES" : "NO") << "\n";
        }
    }

    return 0;
}
