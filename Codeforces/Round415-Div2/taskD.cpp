#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;

bool qry(int first, int second) {
    cout << "1 " << first << " " << second << endl;
    string result; cin >> result;
    return (result == "TAK");
}

int findAns(int l,int r) {
    int res = -1;
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(qry(mid,mid + 1)) {
            res = mid;
            r = mid;
        }
        else
            l = mid + 1;
    }
    return (l == r ? l : res);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin >> n >> k;
    int center = findAns(1,n);
    int left = findAns(1,center - 1);
    int right = findAns(center + 1,n);
    // cout << "center: " << center << endl;
    // cout << "left: " << left << endl;
    // cout << "right: " << right << endl;
    if(left == -1)
        cout << "2 " << center << " " << right << endl;
    else if(right == -1)
        cout << "2 " << center << " " << left << endl;
    else {
        bool result = qry(left, right);
        cout << "2 " << center << " ";
        cout << (result ? left : right) << endl;
    }

    return 0;
}
