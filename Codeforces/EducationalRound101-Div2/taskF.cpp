#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
int n,k;
vector<int> arr;

bool check(int mxDepth) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int curCnt = 1;
    pq.push({0,1});
    if(curCnt>=k)
        return true;
    int best = 0;
    for(int i=0; i<n; i++) {
        pair<int,int> cur = pq.top(); // height, length
        pq.pop();
        if(cur.first<=mxDepth)
            curCnt--;
        cur.first++; cur.second--;
        if(cur.second)
            pq.push(cur);
        pair<int,int> right = {cur.first+1,(arr[i]-1)/2};
        pair<int,int> left = {cur.first+1,arr[i]/2};
        pq.push(right);
        pq.push(left);
        if(right.first<=mxDepth)
            curCnt += min(mxDepth,right.first+right.second-1) - right.first + 1;
        if(left.first<=mxDepth)
            curCnt += min(mxDepth,left.first+left.second-1) - left.first + 1;
        best = max(best,curCnt);
        if(curCnt>=k)
            return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    arr.assign(n,0);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr.rbegin(),arr.rend());
    const int BOUND = int(1e6)+5;
    int l = 0,r = BOUND;
    int ans = -1;
    while(l<=r) {
        int mid = l+(r-l)/2;
        if(check(mid)) {
            ans = mid;
            r = mid-1;
        }
        else
            l = mid+1;
    }
    cout << ans << "\n";

    return 0;
}
