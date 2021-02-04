#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
int n;
const int mxN = int(5e3) + 5;
vector<int> bucket[2][2];
string s,t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> s >> t;
    int tot = 0;
    for(int i=0; i<n; i++) {
        bucket[s[i] - '0'][t[i] - '0'].push_back(i);
        tot += (t[i] == '1');
    }
    for(int number=0; number<=n/2; number++) {
        for(int last=0; last<=sz(bucket[1][1]); last++) {
            if(last > number || last > tot - number) continue;
            int needThird = number - last;
            if(needThird < 0 || needThird > sz(bucket[1][0])) continue;
            int needSecond = tot - number - last;
            if(needSecond < 0 || needSecond > sz(bucket[0][1])) continue;
            int needFirst = n/2 - needThird - needSecond - last;
            if(needFirst < 0 || needFirst > sz(bucket[0][0])) continue;
            for(int i=0; i<needFirst; i++)
                cout << bucket[0][0][i]+1 << " ";
            for(int i=0 ;i<needSecond; i++)
                cout << bucket[0][1][i]+1 << " ";
            for(int i=0; i<needThird; i++)
                cout << bucket[1][0][i]+1 << " ";
            for(int i=0; i<last; i++)
                cout << bucket[1][1][i]+1 << " ";
            cout << "\n";
            goto end;
        }
    }
    cout << "-1\n";
    end:;
    
    return 0;
}
