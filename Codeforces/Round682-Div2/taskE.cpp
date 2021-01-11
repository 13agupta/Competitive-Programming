#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    set<pair<int,int>> res;
    for(int k=30; ~k; k--) {
        for(int i=0; i<n-2; i++) {
            if(31-__builtin_clz(arr[i])!=k) continue;
            int cur = 0;
            for(int j=i+1; j<n-1; j++) {
                cur += arr[j];
                if(cur>=(1<<(k+1))) break;
                if((arr[j+1]^arr[i])==cur)
                    res.insert({i,j+1});
            }
        }
        for(int i=n-1; i>=2; i--) {
            if(31-__builtin_clz(arr[i])!=k) continue;
            int cur = 0;
            for(int j=i-1; j>=1; j--) {
                cur += arr[j];
                if(cur>=(1<<(k+1))) break;
                if((arr[j-1]^arr[i])==cur)
                    res.insert({j-1,i});
            }
        }
    }
    cout << sz(res) << "\n";

    return 0;
}
