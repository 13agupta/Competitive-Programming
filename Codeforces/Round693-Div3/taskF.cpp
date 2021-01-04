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
        int n,m;
        cin >> n >> m;
        vector<pair<int,int>> arr(m);
        for(int i=0; i<m; i++)
            cin >> arr[i].first >> arr[i].second;
        sort(arr.begin(),arr.end(),[](pair<int,int> &f,pair<int,int> &s) {
                if(f.second==s.second)
                    return f.first<s.first;
                return f.second<s.second;
            });
        arr.push_back({1,n+1});
        arr.push_back({2,n+1});
        m += 2;
        int state = -1;
        int cur = 0;
        while(cur!=m) {
            if(cur<m-1 && arr[cur].second==arr[cur+1].second) {
                if(state!=-1) {
                    cout << "NO\n";
                    goto end;
                }
                cur += 2;
                continue;
            }
            if(state==-1) {
                state = (arr[cur].first+arr[cur].second)&1;
                cur++;
                continue;
            }
            int new_state = (arr[cur].first+arr[cur].second)&1;
            if(new_state==state) {
                cout << "NO\n";
                goto end;
            }
            state = -1;
            cur++;
        }
        cout << "YES\n";
        end:;
    }

    return 0;
}
