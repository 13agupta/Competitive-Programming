#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
int n;
const int mxN=2e3+5;
int arr[mxN][mxN];
ll tot[mxN][mxN];

bool chk(pair<int,int> p) {
    return (p.first>=0 && p.first<n && p.second>=0 && p.second<n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<vector<int>> arr(n,vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    }
    set<pair<short,short>> start;
    for(int i=0; i<n; i++) {
        start.insert({0,i});
        start.insert({i,0});
    }
    for(auto p : start) {
        pair<int,int> si=p;
        ll cur=0;
        while(chk(p)) {
            cur+=arr[p.first][p.second];
            p.first++; p.second++;
        }
        while(chk(si)) {
            tot[si.first][si.second]=cur;
            si.first++; si.second++;
        }
    }
    start.clear();
    for(int i=0; i<n; i++) {
        start.insert({i,0});
        start.insert({n-1,i});
    }
    for(auto p : start) {
        pair<int,int> si=p;
        ll cur=0;
        while(chk(p)) {
            cur+=arr[p.first][p.second];
            p.first--; p.second++;
        }
        while(chk(si)) {
            tot[si.first][si.second]+=cur-arr[si.first][si.second];
            si.first--; si.second++;
        }
    }
    pair<int,int> best[2];
    best[0]={0,0}; best[1]={1,0};
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            ll cur=tot[i][j];
            if((i+j)%2 && cur>tot[best[1].first][best[1].second])
                best[1]={i,j};
            else if((i+j)%2==0 && cur>tot[best[0].first][best[0].second])
                best[0]={i,j};
        }
    }
    ll result=tot[best[0].first][best[0].second] + tot[best[1].first][best[1].second];
    cout << result << "\n";
    cout << best[0].first+1 << " " << best[0].second+1 << " " << best[1].first+1 << " " << best[1].second+1 << "\n";

    return 0;
}
