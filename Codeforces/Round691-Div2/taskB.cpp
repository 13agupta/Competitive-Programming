#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int dir[2];
    dir[0]=(n+1)/2;
    dir[1]=n/2;
    set<pair<int,int>> se;
    for(int x=-dir[1]; x<=dir[1]; x++) {
        for(int y=-dir[0]; y<=dir[0]; y++) {
            if(((dir[0]&1)==(y&1)) && ((dir[1]&1)==(x&1)))
                se.insert({x,y});
        }
    }
    for(int x=-dir[0]; x<=dir[0]; x++) {
        for(int y=-dir[1]; y<=dir[1]; y++) {
            if(((dir[1]&1)==(y&1)) && ((dir[0]&1)==(x&1)))
                se.insert({x,y});
        }
    }
    cout << sz(se);

    return 0;
}
