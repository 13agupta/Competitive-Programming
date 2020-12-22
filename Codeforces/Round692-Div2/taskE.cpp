#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int64_t t;
    cin >> n >> t;
    string s;
    cin >> s;
    t-=(1LL<<(s.back()-'a'));
    s.pop_back();
    t+=(1LL<<(s.back()-'a'));
    s.pop_back();
    t=abs(t);
    int cnt[52];
    memset(cnt,0,sizeof(cnt));
    for(int i=0; i<sz(s); i++) {
        t+=(1LL<<(s[i]-'a'));
        cnt[s[i]-'a'+1]++;
    }
    if(t<0) {
        cout << "No\n";
        return 0;
    }
    for(int i=0; i<51; i++) {
        if(t&1) {
            if(cnt[i]==0) {
                cout << "No\n";
                return 0;
            }
            cnt[i]--;
            t--;
        }
        cnt[i+1]+=cnt[i]/2;
        t>>=1;
    }
    cout << "Yes\n";

    return 0;
}
