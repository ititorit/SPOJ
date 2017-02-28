#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define REPD(i,a) for (int i = a; i > 0; i--)
 
#define ll long long
#define fi first
#define se second
 
typedef pair<int, int> pii;
typedef pair< ll, ll > pll;
 
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fLL
 
#define debug(x) { cout << "---> " << #x << " = " << x << endl;  }
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()
 
const int MN = 1e5+5;
int n, m;
int it[270000];
bool lazy[270000];
 
void updateIT(int l, int r, int u, int v, int root) {
    if(lazy[root] != false) {
        it[root] = r - l + 1 - it[root];
        if(l != r) {
            lazy[root<<1] = !lazy[root<<1];
            lazy[root<<1|1] = !lazy[root<<1|1];
        }
        lazy[root] = false;
    }
    if(u > r or v < l) return;
    if(u <= l and r <= v) {
        it[root] = r - l + 1 - it[root];
        if(l != r) {
            lazy[root<<1] = !lazy[root<<1];
            lazy[root<<1|1] = !lazy[root<<1|1];
        }
        return;
    }
    int mid = (l + r) >> 1;
    updateIT(l,mid,u,v,root<<1);
    updateIT(mid+1,r,u,v,root<<1|1);
    if(l != r) it[root] = it[root<<1] + it[root<<1|1];
}
 
int query(int l, int r, int u, int v, int root) {
    if(lazy[root] != false) {
        it[root] = r - l + 1 - it[root];
        if(l != r) {
            lazy[root<<1] = !lazy[root<<1];
            lazy[root<<1|1] = !lazy[root<<1|1];
        }
        lazy[root] = false;
    }
    if(u > r or v < l) return 0;
    if(u <= l and r <= v) {
        return it[root];
    }
    int mid = (l + r) >> 1;
    return query(l,mid,u,v,root<<1) + query(mid+1,r,u,v,root<<1|1);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    FOR(i,1,m) {
        int key, u, v;
        cin >> key >> u >> v;
        if(key == 1) {
            cout << query(1,n,u,v,1) << endl;
        } else {
            updateIT(1,n,u,v,1);
        }
    }
} 
