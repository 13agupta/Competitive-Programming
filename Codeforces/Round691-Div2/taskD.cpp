#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
const int mxN=105;
int dp[mxN][mxN*mxN],tmp[mxN][mxN*mxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(15);

    int n;
    cin >> n;
    memset(dp,-1,sizeof(dp));
    vector<pair<int,int>> arr(n);
    int tot=0;
    for(int i=0; i<n; i++) {
        cin >> arr[i].first >> arr[i].second;
        tot+=arr[i].second;
    }
    for(int i=0; i<n; i++) {
        memcpy(tmp,dp,sizeof(dp));
        for(int k=1; k<=n; k++) {
            if(k>i+1) continue;
            for(int A=0; A<mxN*mxN; A++) {
                if(A-arr[i].first==0 && k==1)
                    tmp[k][A]=max(tmp[k][A],arr[i].second);
                else if(A-arr[i].first>0 && dp[k-1][A-arr[i].first]!=-1)
                    tmp[k][A]=max(tmp[k][A],dp[k-1][A-arr[i].first]+arr[i].second);
            }
        }
        memcpy(dp,tmp,sizeof(tmp));
    }
    for(int i=1; i<=n; i++) {
        for(int j=0; j<25; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    for(int k=1; k<=n; k++) {
        double best=0;
        for(int A=0; A<mxN*mxN; A++) {
            if(dp[k][A]==-1) continue;
            best=max(best,
                    min(double(A),dp[k][A] + (tot-dp[k][A])/2.0));
        }
        cout << best << " ";
    }
    cout << "\n";

    return 0;
}
