#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
const int LOG = 21;
const int INF = int(2e9) + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        int n,k;
        string s;
        cin >> n >> k >> s;
        for(int i=0; i<n; i++)
            s[i] = ('0'+'1'-s[i]);
        vector<int> locations;
        for(int i=0; i<n; i++)
            if(s[i]=='1')
                locations.push_back(i);
        vector<bool> seen(n+1,false);
        int location_idx = 0;
        unsigned value = 0;
        for(int i=0; i<n; i++) {
            int start = i-(k-1);
            value = (value<<1)|(s[i]-'0');
            if(k<32)
                value &= (1U << k) - 1;
            if(start>=0) {
                while(location_idx<sz(locations) && locations[location_idx]<start)
                    location_idx++;
                if(location_idx>=sz(locations) || locations[location_idx]>i-LOG)
                    if(value<=unsigned(n))
                        seen[value]=true;
            }
        }
        int limit = min(n+1,(k<=LOG ? 1<<k : INF));
        int ans = 0;
        while(ans<limit && seen[ans])
            ans++;
        if(ans>=limit) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int i=k-1; ~i; i--)
            cout << (i>=LOG ? 0 : ((ans>>i)&1));
        cout << "\n";
    }

    return 0;
}
