#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
const int INF=1e9+5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;
    int C;
    cin >> C;
    vector<pair<int,int>> vec={{-INF,-INF},{INF,INF},{-INF,INF},{INF,-INF}};
    vector<pair<int,int>> sign={{1,1},{-1,-1},{1,-1},{-1,1}};
    for(int i=0; i<C; i++) {
        int x,y;
        cin >> x >> y;
        for(int j=0; j<4; j++) {
            if(sign[j].first*x + sign[j].second*y>sign[j].first*vec[j].first + sign[j].second*vec[j].second)
                vec[j]={x,y};
        }
    }
    int H;
    cin >> H;
    pair<int,int> best={2e9,-1};
    for(int i=0; i<H; i++) {
        int x,y;
        cin >> x >> y;
        pair<int,int> cur={0,0};
        for(int j=0; j<sz(vec); j++) {
            int dist=abs(vec[j].first-x)+abs(vec[j].second-y);
            if(dist>cur.first) {
                cur.first=dist;
                cur.second=i;
            }
        }
        if(cur.first<best.first)
            best=cur;
    }
    cout << best.first << "\n" << best.second+1 << "\n";

    return 0;
}
