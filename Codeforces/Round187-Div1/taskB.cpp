#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x,y;
    string a,b;
    cin >> x >> y;
    cin >> a >> b;
    int prep[105];
    for(int i=0; i<sz(b); i++) {
        prep[i]=0;
        for(int j=0; j<sz(a); j++)
            if(a[j]==b[(i+prep[i])%sz(b)])
                prep[i]++;
    }
    int res=0;
    for(int i=0; i<x; i++)
        res+=prep[res%sz(b)];
    cout << (res/sz(b))/y;

    return 0;
}
