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
        int n,x;
        cin >> n >> x;
        vector<int> arr(n);
        int64_t res = 0;
        bool done = false;
        vector<int> cnts;
        int mn = 1000;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
            int cnt = 0;
            int oval = arr[i];
            if(oval%x!=0) done = true;
            if(!done && oval%x==0) {
                while(oval%x==0) {
                    oval/=x;
                    cnt++;
                }
            }
            mn = min(mn,cnt);
            cnts.push_back(cnt);
        }
        done = false;
        for(int i=0; i<n; i++) {
            if(!done && cnts[i]!=mn)
                res += (min(cnts[i],mn+1) + 1) * 1LL * arr[i];
            else if(!done && cnts[i]==mn) {
                res += (cnts[i]+1) * 1LL * arr[i];
                done = true;
            }
            else
                res += (min(cnts[i],mn) + 1) * 1LL * arr[i];
        }
        cout << res << "\n";
    }
    
    return 0;
}
