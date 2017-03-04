// author: ititorit ( Rentt )
// Link  : http://www.spoj.com/problems/KGSS/
// algo  : Segment Tree ( Interval Tree )

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
ll n, m, a[MN];

struct Node {
    int fi, se; // fi -> max | se -> min...
    Node() {
        fi = se = -inf;
    }
    Node(int val) {
        fi = val;
        se = -inf;
    }
    Node(int _fi, int _se) {
        fi = _fi; se = _se;
    }
    void merge(Node left, Node right) {
        vector<int> res(4);
        res[0] = left.fi;
        res[1] = left.se;
        res[2] = right.fi;
        res[3] = right.se;
        sort(all(res));
        fi = res[3]; se = res[2];
    }
} it[MN << 2];

void build(int l, int r, int pos) {
    if(l == r) {
        it[pos].fi = a[l];
        it[pos].se = -inf;
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,pos<<1);
    build(mid+1,r,pos<<1|1);
    it[pos].merge(it[pos<<1], it[pos<<1|1]);
    return;
}

Node query(int l, int r, int u, int v, int pos) {
    if(l > r or v < l or u > r) {
        return Node();
    }
    if(u <= l and r <= v) return it[pos];
    int mid = (l + r) >> 1;
    Node _l = query(l,mid,u,v,pos<<1);
    Node _r = query(mid+1,r,u,v,pos<<1|1);
    Node res = Node();
    res.merge(_l, _r);
    return res;
}

void update(int l, int r, int id, int val, int pos) {
    if(l == r) {
        it[pos] = Node(val);
        return;
    }
    int mid = (l + r) >> 1;
    if(id <= mid) {
        update(l,mid,id,val,pos<<1);
    } else {
        update(mid+1,r,id,val,pos<<1|1);
    }
    it[pos] = Node();
    it[pos].merge(it[pos<<1], it[pos<<1|1]);
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    FOR(i,1,n) cin >> a[i];
    build(1,n,1);

    cin >> m;
    while(m--) {
        char key;
        cin >> key;
        if(key == 'Q') {
            int l, r; cin >> l >> r;
            Node res = query(1,n,l,r,1);
            cout << res.fi + res.se << endl;
            continue;
        }
        int id, val;
        cin >> id >> val;
        update(1,n,id,val,1);
    }
}
