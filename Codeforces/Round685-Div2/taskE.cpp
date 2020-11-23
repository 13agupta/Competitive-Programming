#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;

int qry(int first,int second,int type) {
    if(type==1)
        cout << "XOR " << first+1 << " " << second+1 << endl;
    else
        cout << "AND " << first+1 << " " << second+1 << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    set<int> se;
    vector<int> arr(n,0);
    se.insert(0);
    int same=-1;
    for(int i=1; i<n; i++) {
        arr[i]=qry(0,i,1);
        if(se.find(arr[i])!=se.end())
            same=i;
        se.insert(arr[i]);
    }
    if(same!=-1) {
        vector<int> sinds;
        int cur=0;
        while(sz(sinds)<2) {
            if(arr[cur]==arr[same])
                sinds.push_back(cur);
            cur++;
        }
        int val=qry(sinds[0],sinds[1],2);
        arr[0]=arr[sinds[0]]^val;
        for(int i=1; i<n; i++)
            arr[i]^=arr[0];
        cout << "! ";
        for(int i=0; i<n; i++)
            cout << arr[i] << " ";
        cout << endl;
        return 0;
    }
    int ind=-1;
    for(int i=1; i<n; i++) {
        if(arr[i]==1)
            ind=i;
    }
    int sind=-1;
    for(int i=1; i<n; i++) {
        if(arr[i]%2==0)
            sind=i;
    }
    int fval=qry(0,ind,2);
    int sval=qry(0,sind,2);
    arr[0]=fval|sval;
    for(int i=1; i<n; i++)
        arr[i]^=arr[0];
    cout << "! ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
