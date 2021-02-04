#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;

vector<string> qry(vector<int> arr) {
    cout << "next ";
    for(auto e : arr)
        cout << e << " ";
    cout << endl;
    int k; cin >> k;
    vector<string> res(k);
    for(int i=0; i<k; i++)
        cin >> res[i];
    return res;
}

bool checkSame(vector<string> arr,int first,int second) {
    vector<set<int>> se(sz(arr));
    for(int i=0; i<sz(arr); i++) {
        for(char c : arr[i])
            se[i].insert(c - '0');
        if(se[i].find(first) != se[i].end() && se[i].find(second) != se[i].end())
            return true;
    }
    return false;
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> cur;
    while(!checkSame(cur,0,1)) {
        qry({0});
        cur = qry({0,1});
    }
    vector<int> qryVector(10);
    iota(qryVector.begin(),qryVector.end(),0);
    while(!checkSame(cur,0,2))
        cur = qry(qryVector);
    cout << "done" << endl;

    return 0;
}
