#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
const int mxN = int(1e5) + 5;
char s[mxN],ans[mxN];
int sum[mxN];
int n;

bool check() {
    for(int i=0; i<n/2; ) {
        if(sum[i]==sum[n-i-1]) i++;
        else if(sum[i]==sum[n-i-1]+1 || sum[i]==sum[n-i-1]+11) {
            sum[i]--;
            sum[i+1] += 10;
        }
        else if(sum[i]==sum[n-i-1]+10) {
            sum[n-i-2]--;
            sum[n-i-1] += 10;
        }
        else
            return false;
    }
    if(n%2==1) {
        if(sum[n/2]%2==1 || sum[n/2]>18 || sum[n/2]<0)
            return false;
        else
            ans[n/2] = sum[n/2]/2 + '0';
    }
    for(int i=0; i<n/2; i++) {
        if(sum[i]>18 || sum[i]<0)
            return false;
        ans[i] = (sum[i] + 1)/2 + '0';
        ans[n-i-1] = sum[i]/2 + '0';
    }
    return ans[0] > '0';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%s", s);
    n = strlen(s);
    for(int i=0; i<n; i++)
        sum[i] = s[i] - '0';
    if(check())
        puts(ans);
    else if(s[0]=='1' && n>1) {
        for(int i=0; i<n; i++)
            sum[i] = s[i+1] - '0';
        n--;
        sum[0] += 10;
        if(check())
            puts(ans);
        else
            cout << "0\n";
    }
    else
        cout << "0\n";

    return 0;
}
