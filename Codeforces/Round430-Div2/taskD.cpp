#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
int n,tt,a,x,ans;
bool chk[300005];
 
struct node
{
	int cnt;
	node *c[2];
	
	node()
	{
		c[0] = c[1] = nullptr;
		cnt = 0;
	}
} *root;
 
void build(node *cur, int l)
{
	++(cur -> cnt);
	if (l == 0)
		return;
	--l;
	if (cur -> c[(a >> l) & 1] == nullptr)
		cur -> c[(a >> l) & 1] = new node();
	build(cur -> c[(a >> l) & 1], l);
}
 
void get(node *cur, int l)
{
	if (l == 0)
		return;
	--l;
	int m = (x >> l) & 1;
	if (cur -> c[m] == nullptr)
		return;
	else if (cur -> c[m] -> cnt < (1 << l))
	{
		get(cur -> c[m], l);
		return;
	}
	ans += (1 << l); m = 1 - m;
	if (cur -> c[m] == nullptr)
		return;
	else get(cur -> c[m], l);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> tt;
    root = new node();
    for(int i=0; i<n; i++) {
        cin >> a;
        if(!chk[a]) {
            chk[a]=true;
            build(root, 20);
        }
    }
    while(tt--) {
        cin >> a;
        ans=0;
        x^=a;
        get(root, 20);
        cout << ans << "\n";
    }

    return 0;
}
