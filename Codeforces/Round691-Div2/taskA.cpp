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
        int cnt[2];
        cnt[0]=cnt[1]=0;
        string s,t;
        cin >> s >> t;
        for(int i=0; i<n; i++) {
            if(s[i]<t[i])
                cnt[0]++;
            else if(s[i]>t[i])
                cnt[1]++;
        }
        if(cnt[0]>cnt[1])
            cout << "BLUE\n";
        else if(cnt[0]<cnt[1])
            cout << "RED\n";
        else
            cout << "EQUAL\n";
    }

    return 0;
}
