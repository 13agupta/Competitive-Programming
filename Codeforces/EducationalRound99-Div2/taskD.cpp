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
        for(int i=0; i<n; i++)
            cin >> arr[i];
        vector<bool> pref(n,true);
        pref[n-1]=true;
        for(int i=n-2; ~i; i--)
            pref[i]=(pref[i+1] && (arr[i]<=arr[i+1]));
        int cnt=0;
        for(int i=0; i<n; i++) {
            if(pref[i]) {
                if(!i) break;
                else if(arr[i-1]<=arr[i]) break;
            }
            if(x<arr[i]) {
                swap(x,arr[i]);
                cnt++;
            }
        }
        for(int i=1; i<n; i++)
            if(arr[i-1]>arr[i]) {
                cnt=-1;
                break;
            }
        cout << cnt << "\n";
    }

    return 0;
}
