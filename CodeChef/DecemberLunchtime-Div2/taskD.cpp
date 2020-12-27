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
        string s;
        cin >> s;
        vector<int> arr(26,0);
        for(int i=0; i<sz(s); i++)
            arr[s[i]-'a']++;
        int cnt[2];
        cnt[0]=cnt[1]=0;
        for(int i=0; i<26; i++) {
            cnt[0]+=arr[i]/2;
            cnt[1]+=arr[i]%2;
        }
        int best=0;
        while(cnt[0]) {
            best=max(best,min(cnt[0],cnt[1]));
            cnt[0]--;
            cnt[1]+=2;
        }
        cout << best << "\n";
    }

    return 0;
}
