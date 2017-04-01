// Author: ititorit ( Rentt )
// Link: http://www.spoj.com/problems/COURAGE/
// Lang: C/C++
// Algo: Segment Tree ( Interval Tree )

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define REPD(i,a) for (int i = a; i > 0; i--)
 
#define ll long long
#define fi first
#define se second
 
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fLL
 
#define debug(x) { cout << "---> " << #x << " = " << x << endl;  }
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()
 
const int MN = 1e5+5;

ll read(){
    char r;
    bool start = false, neg = false;
    ll res = 0;
    while( true ) {
	r = getchar();
	if((r - '0' < 0 or r - '0' > 9) and r != '-' && !start) {
	    continue;
	}
	if((r - '0' < 0 or r - '0' > 9) and r != '-' && start) {
	    break;
	}
	if(start) res *= 10;
	    start = true;
	    if(r == '-') neg = true;
	    else res += r - '0';
    }
    if(!neg) return res;
    else return -res;
}

ll a[MN];

struct Node {

    ll mn, sum;
    Node() {
        mn = inf;
        sum = 0;
    }
    Node(ll _mn, ll _sum) {
        mn = (_mn);
        sum = (_sum);
    }

    void merge(Node l, Node r) {
        mn = min(l.mn, r.mn);
        sum = l.sum + r.sum;
    }

} it[MN << 2];

void build(int l, int r, int pos) {
    if(l == r) {
        it[pos].sum = it[pos].mn = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,pos<<1);
    build(mid+1,r,pos<<1|1);

    it[pos].merge( it[pos<<1], it[pos<<1|1]);
    return;
}

void update(int l, int r, int idx, int val, int pos) {
    if(idx < l or idx > r) return ;
    if(l == r) {
        it[pos].sum += val;
        it[pos].mn += val;
        return ;
    }
    
    int mid = (l + r) >> 1;
    if(idx <= mid) update(l,mid,idx,val,pos<<1);
    else update(mid+1,r,idx,val,pos<<1|1);

    it[pos].merge( it[pos<<1], it[pos<<1|1] );
    return ;
}

Node query(int l, int r, int u, int v, int pos) {
    if(l > r or u > r or v < l) return Node();
    if(u <= l and r <= v) return it[pos];
    
    int mid = (l + r) >> 1;
    Node _l = query(l,mid,u,v,pos<<1);
    Node _r = query(mid+1,r,u,v,pos<<1|1);

    Node res = Node(0, 0);
    res.merge(_l, _r);
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = read();
    FOR(i,1,n) a[i] = read();
    build(1,n,1);
    int q = read();
    while(q--) {
        char tp[20];
        scanf("%s", tp);
        if(tp[0] == 'C') {
            int l = read();
            int r = read();
            l++;
            r++;
            Node res = query(1,n,l,r,1);
            printf("%lld\n", res.sum - res.mn);
        } else if(tp[0] == 'E') {
            int val = read();
            int idx = read();
            idx++;
            update(1,n,idx,-val,1);
        } else {
            int val = read();
            int idx = read();
            idx++;
            update(1,n,idx,val,1);
        }
    }
    return 0;
}
