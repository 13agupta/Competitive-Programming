#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;

bool chk(vector<int> &cnt) {
    int tot=0;
    for(int i=0; i<22; i++)
        tot+=cnt[i];
    return (tot>0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> cnt(22,0);
    for(int i=0; i<n; i++) {
        int e;
        cin >> e;
        for(int i=0; i<=20; i++) {
            if((e>>i)&1)
                cnt[i]++;
        }
    }
    ll tot=0;
    while(chk(cnt)) {
        int cur=0;
        for(int i=21; ~i; i--) {
            cur<<=1;
            if(cnt[i]) {
                cur|=1;
                cnt[i]--;
            }
        }
        tot+=cur*1LL*cur;
    }
    cout << tot;

    return 0;
}
