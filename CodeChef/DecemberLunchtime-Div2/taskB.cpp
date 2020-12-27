#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
int n,m;

bool check(vector<vector<int>> &arr,int x,int y) {
    pair<int,int> cur={x,y};
    int prev=arr[cur.first][cur.second];
    while(cur.first<n && cur.second<m) {
        if(arr[cur.first][cur.second]!=prev)
            return false;
        prev=arr[cur.first][cur.second];
        cur.first++; cur.second++;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        cin >> n >> m;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++)
                cin >> arr[i][j];
        }
        vector<bool> status(n+m,true);
        for(int j=1; j<n; j++)
            status[j-1]=check(arr,j,0);
        for(int j=0; j<m; j++)
            status[n-1+j]=check(arr,0,j);
        int q;
        cin >> q;
        while(q--) {
            int x,y,v;
            cin >> x >> y >> v;
            x--; y--;
            arr[x][y]=v;
            int mn=min(x,y);
            x-=mn; y-=mn;
            if(x!=0)
                status[x-1]=check(arr,x,y);
            else
                status[n-1+y]=check(arr,x,y);
            bool res=true;
            for(int i=0; i<n+m; i++)
                res=(res && status[i]);
            cout << (res ? "Yes" : "No") << "\n";
        }
    }

    return 0;
}
