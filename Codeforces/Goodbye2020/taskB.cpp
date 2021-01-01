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
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            cin >> arr[i];
        sort(arr.rbegin(),arr.rend());
        int cur=0;
        int cnt=0;
        int need=2*n+1;
        while(true) {
            if(cur==n)
                break;
            while(arr[cur]!=need && arr[cur]+1!=need) {
                if(need<arr[cur])
                    break;
                need--;
            }
            if(arr[cur]==need || arr[cur]+1==need) {
                cnt++;
                need--;
            }
            cur++;
        }
        cout << cnt << "\n";
    }

    return 0;
}
