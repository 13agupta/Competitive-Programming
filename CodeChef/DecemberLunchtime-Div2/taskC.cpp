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
        string s,t;
        int n;
        cin >> n;
        cin >> s >> t;
        vector<int> chk(n,0);
        int cnt[2];
        cnt[0]=cnt[1]=0;
        for(int i=0; i<n; i++) {
            cnt[0]+=(s[i]=='0');
            cnt[1]+=(t[i]=='0');
            if(s[i]!=t[i]) {
                if(s[i]=='0')
                    chk[i]=-1;
                else
                    chk[i]=1;
            }
        }
        if(cnt[0]!=cnt[1]) {
            cout << "No\n";
            continue;
        }
        int cur=0;
        for(int i=0; i<n; i++) {
            if(chk[i]!=1) continue;
            cur=max(cur,i+1);
            while(cur!=n && chk[cur]!=-1) cur++;
            if(cur==n) {
                cout << "No\n";
                goto end;
            }
            cur++;
        }
        cout << "Yes\n";
        end:;
    }

    return 0;
}
