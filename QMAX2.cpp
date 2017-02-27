// author : Rentt (ititorit)
// Link   : http://vn.spoj.com/problems/QMAX2/
// algo   : Interval Tree ( Segment Tree ) + Lazy propagation algortithm

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

const int MN = 50050;
int n, m, q, it[MN << 2], lazy[MN << 2];

void updateIT(int l, int r, int u, int v, int k, int pos) {
    if(lazy[pos] != 0) {
        it[pos] += lazy[pos];
        if(l != r) {
            lazy[pos<<1] += lazy[pos];
            lazy[pos<<1|1] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(u > r or v < l) return;
    if(u <= l and r <= v) {
        it[pos] += k;
        if(l != r) {
            lazy[pos<<1] += k;
            lazy[pos<<1|1] += k;
        }
        return;
    }
    int mid = (l + r) >> 1;
    updateIT(l,mid,u,v,k,pos<<1);
    updateIT(mid+1,r,u,v,k,pos<<1|1);
    it[pos] = max(it[pos<<1],it[pos<<1|1]);
}

int query(int l, int r, int u, int v, int pos) {
    if(lazy[pos] != 0) {
        it[pos] += lazy[pos];
        if(l != r) {
            lazy[pos << 1] += lazy[pos];
            lazy[pos << 1|1] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(u > r or v < l) return 0;
    if(u <= l and r <= v) {
        return it[pos];
    }
    int mid = (l + r) >> 1;
    return max(query(l,mid,u,v,pos<<1), query(mid+1,r,u,v,pos<<1|1));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    FOR(i,1,m) {
        int key;
        cin >> key;
        if(key == 0) {
            int u, v, k;
            cin >> u >> v >> k;
            updateIT(1,n,u,v,k,1);
        } else if(key == 1) {
            int u, v;
            cin >> u >> v;
            cout << query(1,n,u,v,1) << endl;
        }
    }
}
