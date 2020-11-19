#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    string s;
    cin >> k >> s;
    set<int> se;
    deque<pair<char,int>> arr;
    for(int i=0; i<k; i++) {
        while(!arr.empty() && s[i]<=arr.back().first)
            arr.pop_back();
        arr.push_back({s[i],i});
    }
    se.insert(arr.front().second);
    pair<char,int> prev=arr.front();
    for(int i=k; i<sz(s); i++) {
        if(arr.front().second==i-k)
            arr.pop_front();
        while(!arr.empty() && s[i]<=arr.back().first)
            arr.pop_back();
        arr.push_back({s[i],i});
        if(arr.front().first==prev.first && prev.second>i-k)
            continue;
        else {
            se.insert(arr.front().second);
            prev=arr.front();
        }
    }
    char worst='a';
    for(auto i : se)
        worst=max(worst,s[i]);
    for(int i=0; i<sz(s); i++) {
        if(s[i]<worst)
            se.insert(i);
    }
    vector<char> res;
    for(auto i : se)
        res.push_back(s[i]);
    sort(res.begin(),res.end());
    for(auto c : res)
        cout << c;

    return 0;
}
