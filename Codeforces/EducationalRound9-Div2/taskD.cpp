#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
const int mxN=1e6+5;
int arr[mxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;
    vector<int> a;
    for(int i=0; i<n; i++) {
        int e;
        cin >> e;
        a.push_back(e);
        if(e>m)
            continue;
        arr[e]++;
    }
    for(int i=m; i>0; i--) {
        if(arr[i]) {
            int cur=2*i;
            while(cur<=m) {
                arr[cur]+=arr[i];
                cur+=i;
            }
        }
    }
    int best=0,bestVal=1;
    for(int i=1; i<=m; i++) {
        if(best<arr[i]) {
            best=arr[i];
            bestVal=i;
        }
    }
    vector<int> res;
    for(int i=0; i<n; i++) {
        if(bestVal%a[i]==0)
            res.push_back(i+1);
    }
    cout << bestVal << " " << sz(res) << "\n";
    for(int i=0; i<sz(res); i++)
        cout << res[i] << " ";

    return 0;
}
