#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
deque<char> s;
vector<int> ranges;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tt;
    cin >> tt;
    while(tt--) {
        int a,b;
        cin >> a >> b;
        string st;
        cin >> st;
        s.clear();
        ranges.clear();
        for(int i=0; i<sz(st); i++)
            s.push_back(st[i]);
        while(!s.empty() && s.front()=='0')
            s.pop_front();
        while(!s.empty() && s.back()=='0')
            s.pop_back();
        int tot=0;
        char prev='1';
        int cur=0;
        int cnt=0;
        while(cur!=sz(s)) {
            while(cur!=sz(s) && prev==s[cur]) {
                cnt++;
                cur++;
            }
            ranges.push_back(cnt);
            cnt=0;
            prev=(1-(prev-'0')) + '0';
        }
        if(ranges.empty()) {
            cout << 0 << "\n";
            continue;
        }
        tot=a;
        for(int i=0; i<sz(ranges); i+=2) {
            if(i+1<sz(ranges))
                tot+=min(a,b*ranges[i+1]);
        }
        cout << tot << "\n";
    }
    
    return 0;
}
