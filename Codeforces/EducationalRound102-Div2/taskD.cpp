#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
const int mxN = int(2e5) + 5;
int arr[mxN],t[mxN<<2],lazy[mxN<<2],tmn[mxN<<2];
const int INF = int(1e8) + 5;

void build(int v,int tl,int tr) {
    if(tl==tr) {
        t[v] = tmn[v] = arr[tl];
        return;
    }
    int tm = tl + (tr-tl)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    t[v] = max(t[2*v],t[2*v+1]);
    tmn[v] = min(tmn[2*v],tmn[2*v+1]);
    lazy[v] = 0;
}

void push(int v) {
    t[v*2] += lazy[v];
    tmn[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    tmn[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        tmn[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = max(t[v*2], t[v*2+1]);
        tmn[v] = min(tmn[v*2], tmn[v*2+1]);
    }
}

int qryMx(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -INF;
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return max(qryMx(v*2, tl, tm, l, min(r, tm)), 
               qryMx(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int qryMn(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return INF;
    if (l <= tl && tr <= r)
        return tmn[v];
    push(v);
    int tm = (tl + tr) / 2;
    return min(qryMn(v*2, tl, tm, l, min(r, tm)), 
               qryMn(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        int n,m;
        cin >> n >> m;
        string s;
        cin >> s;
        arr[0] = 0;
        for(int i=1; i<=n; i++)
            arr[i] = (s[i-1]=='+' ? 1 : -1);
        for(int i=1; i<=n; i++)
            arr[i] += arr[i-1];
        build(1,0,n);
        while(m--) {
            int l,r;
            cin >> l >> r;
            int tot = qryMx(1,0,n,r,r) - qryMx(1,0,n,l-1,l-1);
            int mn = INF,mx = -INF;
            mn = min(mn,qryMn(1,0,n,0,l-1));
            mx = max(mx,qryMx(1,0,n,0,l-1));
            update(1,0,n,r+1,n,-tot);
            mn = min(mn,qryMn(1,0,n,r+1,n));
            mx = max(mx,qryMx(1,0,n,r+1,n));
            update(1,0,n,r+1,n,tot);
            cout << mx-mn+1 << "\n";
        }
    }

    return 0;
}
