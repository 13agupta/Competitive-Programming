#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
vector<int> arr,pref,rpref,logs;
vector<vector<int>> st;
int n;
const int K=25;

void build() {
    logs.assign(n+1,0);
    logs[1] = 0;
    for (int i = 2; i <= n; i++)
        logs[i] = logs[i/2] + 1;
    st.assign(n,vector<int>(K,0));
    for (int i = 0; i < n; i++)
        st[i][0] = arr[i];

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
}

int qry(int L,int R) {
    int j = logs[R - L + 1];
    return min(st[L][j], st[R - (1 << j) + 1][j]);
}

void answer(int first,int second) {
    cout << "YES\n";
    cout << first << " " << second-first+1 << " " << n-second-1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        cin >> n;
        arr.assign(n,0);
        pref.assign(n,0);
        rpref.assign(n,0);
        for(int i=0; i<n; i++)
            cin >> arr[i];
        pref[0]=arr[0];
        for(int i=1; i<n; i++)
            pref[i]=max(pref[i-1],arr[i]);
        rpref[n-1]=arr[n-1];
        for(int i=n-2; ~i; i--)
            rpref[i]=max(rpref[i+1],arr[i]);
        build();
        for(int i=1; i<n-1; i++) {
            int l=i,r=n-2;
            int mx=pref[i-1];
            while(l<=r) {
                int mid=l+(r-l)/2;
                int cur=qry(i,mid);
                if(cur<mx)
                    r=mid-1;
                else if(cur>mx)
                    l=mid+1;
                else if(rpref[mid+1]<mx)
                    r=mid-1;
                else if(rpref[mid+1]>mx)
                    l=mid+1;
                else {
                    answer(i,mid);
                    goto end;
                }
            }
        }
        cout << "NO\n";
        end:;
    }

    return 0;
}
