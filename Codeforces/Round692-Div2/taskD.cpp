#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int64_t x,y;
    cin >> x >> y;
    if(x>y) {
        swap(x,y);
        for(int i=0; i<sz(s); i++) {
            if(s[i]=='?') continue;
            s[i]^=1;
        }
    }
    array<int64_t,2> tot{0,0};
    for(int i=0; i<sz(s); i++)
        if(s[i]!='?') tot[s[i]-'0']++;
    vector<array<int64_t,2>> cost;
    array<int64_t,2> cnt{0,0};
    int64_t cur_tot=0;
    for(int i=0; i<sz(s); i++) {
        if(s[i]=='?') {
            cost.push_back({
                    cnt[1]*y + (tot[1]-cnt[1])*x,
                    cnt[0]*x + (tot[0]-cnt[0])*y
                    });
        }
        else {
            if(s[i]=='0') cur_tot+=cnt[1]*y;
            else cur_tot+=cnt[0]*x;
            cnt[s[i]-'0']++;
        }
    }
    int64_t res=2e18,cmd=0;
    for(int i=0; i<sz(cost); i++)
        cmd+=cost[i][1];
    for(int i=0; i<=sz(cost); i++) {
        res=min(res,cur_tot + cmd + i*(sz(cost)-i)*x);
        if(i<sz(cost)) {
            cmd-=cost[i][1];
            cmd+=cost[i][0];
        }
    }
    cout << res;

    return 0;
}
