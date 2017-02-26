#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = b; i >= b; i--)
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
 
const int MN = 50055;
int n,m,q;
 
struct node {
    int mx, upd;
};
 
node it[4*MN];
 
void update(int l, int r, int u, int v, int k, int pos) {
    // no overlap
    if(l > v or r < u) return;
    // total overlap
    if(l >= u and r <= v) {
        it[pos].mx += k;
        it[pos].upd += k;
        return;
    }
    // partial overlap
    int mid = (l + r) >> 1;
    int val = it[pos].upd;
    it[pos<<1].mx += val;
    it[pos<<1].upd+= val;
    it[pos<<1|1].mx += val;
    it[pos<<1|1].upd+= val;
    update(l,mid,u,v,k,pos<<1);
    update(mid+1,r,u,v,k,pos<<1|1);
    it[pos].upd = 0;
    it[pos].mx = max(it[pos<<1].mx, it[pos<<1|1].mx);
}
 
int query(int l, int r, int u, int v, int pos) {
    if(l > v or r < u) return 0;
    if(l >= u and r <= v) return it[pos].mx;
    int mid = (l + r) >> 1;
    int val = it[pos].upd;
    it[pos<<1].mx += val;
    it[pos<<1].upd+= val;
    it[pos<<1|1].mx += val;
    it[pos<<1|1].upd+= val;
    it[pos].upd = 0;
    return max(query(l,mid,u,v,pos<<1),query(mid+1,r,u,v,pos<<1|1));
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    FOR(i,1,m) {
        int u, v, k;
        cin >> u >> v >> k;
        update(1,n,u,v,k,1);
    }
 
    cin >> q;
    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << query(1,n,u,v,1) << endl;
    }
} 
