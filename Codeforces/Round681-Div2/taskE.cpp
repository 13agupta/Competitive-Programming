#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
ll cur;
vector<int> arr;
ll facts[16];
int lastSize,n;

void precompute() {
    facts[1]=1;
    for(int i=2; i<16; i++)
        facts[i]=i*facts[i-1];
}

void findPerm() {
    vector<int> temp;
    for(int i=0; i<sz(arr); i++)
        temp.push_back(arr[i]);
    ll tcur=cur;
    sort(temp.begin(),temp.end());
    for(int i=0; i<sz(arr)-1; i++) {
        int ind=tcur/facts[sz(arr)-1-i];
        arr[i]=temp[ind];
        tcur%=facts[sz(arr)-1-i];
        temp.erase(temp.begin()+ind);
    }
    arr.back()=temp.front();
}

ll firstSum(ll l,ll r) {
    if(l>r)
        return 0;
    return (r*(r+1))/2 - (l*(l-1))/2;
}

ll secondSum(ll l,ll r) {
    if(l>r)
        return 0;
    ll tot=0;
    for(int i=l-(n-lastSize)-1; i<r-(n-lastSize); i++)
        tot+=arr[i];
    return tot;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();
    int tt;
    cin >> n >> tt;
    lastSize=min(n,15);
    arr.assign(lastSize,0);
    for(int i=0; i<lastSize; i++)
        arr[i]=i+(n-lastSize)+1;
    while(tt--) {
        int type;
        cin >> type;
        if(type==2) {
            int x;
            cin >> x;
            cur+=x;
            findPerm();
        }
        else {
            int l,r;
            cin >> l >> r;
            if(r<=n-lastSize)
                cout << firstSum(l,r) << "\n";
            else if(l>n-lastSize)
                cout << secondSum(l,r) << "\n";
            else
                cout << firstSum(l,n-lastSize) + secondSum(n-lastSize+1,r) << "\n";
        }
    }

    return 0;
}
