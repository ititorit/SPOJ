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
int n, a[MN], q, itMin[4*MN + 1], itMax[4*MN + 1];

void buildITMax(int lo, int hi, int pos) {
    if(lo == hi) {
        itMax[pos] = a[lo];
        return;
    }
    int mid = (lo + hi) >> 1;
    buildITMax(lo, mid, pos<<1);
    buildITMax(mid+1,hi,pos<<1|1);
    itMax[pos] = max(itMax[pos<<1], itMax[pos<<1|1]);
}

void buildITMin(int lo, int hi, int pos) {
    if(lo == hi) {
        itMin[pos] = a[lo];
        return;
    }
    int mid = (lo + hi) >> 1;
    buildITMin(lo,mid,pos<<1);
    buildITMin(mid+1,hi,pos<<1|1);
    itMin[pos] = min(itMin[pos<<1],itMin[pos<<1|1]);
}

int queryMax(int l, int r, int lo, int hi, int pos) {
    // total overload
    if(l <= lo and r >= hi) {
        return itMax[pos];
    }
    // no overload
    if(l > hi or r < lo) return -inf;

    int mid = (lo + hi) >> 1;
    return max(queryMax(l,r,lo,mid,pos<<1),
               queryMax(l,r,mid+1,hi,pos<<1|1));
}

int queryMin(int l, int r, int lo, int hi, int pos) {
    if(l <= lo and r >= hi) {
        return itMin[pos];
    }
    if(l > hi or r < lo) return inf;
    int mid = (lo + hi) >> 1;
    return min(queryMin(l,r,lo,mid,pos<<1),
               queryMin(l,r,mid+1,hi,pos<<1|1));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    FOR(i,1,n) cin >> a[i];
    buildITMin(1,n,1);
    buildITMax(1,n,1);
    while(q--) {
        int l, r;
        cin >> l >> r;
        int mx = queryMax(l,r,1,n,1);
        int mn = queryMin(l,r,1,n,1);
        cout << mx - mn << endl;
    }
}
