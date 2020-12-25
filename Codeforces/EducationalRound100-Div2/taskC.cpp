#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
const int64_t INF=4e9+5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<pair<int64_t,int64_t>> arr(n+1);
        for(int i=0; i<n; i++)
            cin >> arr[i].first >> arr[i].second;
        arr[n].first=INF;
        array<int64_t,3> state{0,0,0}; // time, position, go to
        int cnt=0;
        for(int i=0; i<n; i++) {
            int64_t t=state[0];
            int64_t p=state[1];
            int64_t x=state[2];
            int64_t diff=arr[i].first-t;
            int64_t need=x-p;
            if(abs(need)<diff)
                state[1]=x;
            else
                state[1]=p + (need/abs(need))*diff;
            state[0]=arr[i].first;
            if(state[1]==x)
                state[2]=arr[i].second;
            // check whether this instruction succeeds
            // need=arr[i].second-state[1];
            int64_t rem=arr[i+1].first-arr[i].first;
            int64_t left=state[2]-state[1];
            if(abs(left)>rem)
                left=(left/abs(left)) * rem;
            left=state[1]+left;
            if(arr[i].second>=left && arr[i].second<=state[1])
                cnt++;
            else if(arr[i].second>=state[1] && arr[i].second<=left)
                cnt++;
            // cout << state[0] << " " << state[1] << " " << state[2] << endl;
        }
        cout << cnt << "\n";
    }

    return 0;
}
