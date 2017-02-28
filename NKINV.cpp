// author: ititorit ( Rentt )
// link  : http://vn.spoj.com/problems/NKINV/
// algo  : Interval Tree ( Segment Tree )

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
 
const int MN = 60060;
int n, a[MN], it[MN << 2];
 
void update(int l, int r, int u, int v, int pos) {
    // no overlap condition
    if(u > r or v < l) return;
    // total overlap condition
    if(u <= l and r <= v) {
        it[pos] += 1;
        return;
    }
    // partial overlap condition
    int mid = (l + r) >> 1;
    update(l,mid,u,v,pos<<1);
    update(mid+1,r,u,v,pos<<1|1);
    it[pos] = it[pos<<1] + it[pos<<1|1];
}
 
int get(int l, int r, int u, int v, int pos) {
    // no overlap condition
    if(u > r or v < l) return 0;
    // total overlap condition
    if(u <= l and r <= v) return it[pos];
    // partial overlap condition
    int mid = (l + r) >> 1;
    return get(l,mid,u,v,pos<<1) + get(mid+1,r,u,v,pos<<1|1);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int mx = 0;
    FOR(i,1,n) {
        cin >> a[i];
        mx = max(mx,a[i]);
    }
    ll res = 0;
    FORD(i,n,1) {
        res += (ll)get(1,mx,1,a[i]-1,1);
        update(1,mx,a[i],a[i],1);
    }
    cout << res << endl;
} 
