// author: ititorit (Rentt)
// Link  : http://www.spoj.com/problems/CNTPRIME/
// Algo  : Interval Tree ( Segment Tree ) + Lazy Propagation update
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <queue>
#include <bitset>
 
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
 
const ll MN = 1e6+5;
int test, n, m, p[MN], a[MN], it[MN<<2], lazy[MN<<2];
void init() {
    FOR(i,1,MN) p[i]=1;
    p[1]=0;
    int i=2;
    int m1 = (int)sqrt(MN);
    while (i <= m1) {
        while (p[i] == 0) i++;
        for (int j = 2; j <= MN/i; j++)
            p[i*j] = 0;
        i++;
    }
}
 
void build(int l, int r, int pos) {
    if(l == r) {
        it[pos] = p[a[l]];
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,pos<<1); build(mid+1,r,pos<<1|1);
    it[pos] = it[pos<<1] + it[pos<<1|1];
    return;
}

void update(int l, int r, int u, int v, int val, int pos) {
    if(lazy[pos] != 0) {
        if(p[lazy[pos]] == 1) {
            it[pos] = r - l + 1;
        } else {
            it[pos] = 0;
        }
        if(l != r) {
            lazy[pos<<1] = lazy[pos<<1|1] = lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(v < l or u > r) return;
    if(u <= l and r <= v) {
        if(p[val] == 1) {
            it[pos] = r - l + 1;
        } else {
            it[pos] = 0;
        }
        if(l != r) {
            lazy[pos<<1] = lazy[pos<<1|1] = val;
        }
        return;
    }
    int mid = (l + r) >> 1;
    update(l,mid,u,v,val,pos<<1);
    update(mid+1,r,u,v,val,pos<<1|1);
    it[pos] = it[pos<<1] + it[pos<<1|1];
    return;
}

int query(int l, int r, int u, int v, int pos) {
    if(lazy[pos] != 0) {
        if(p[lazy[pos]] == 1) {
            it[pos] = r - l + 1;
        } else {
            it[pos] = 0;
        }
        if(l != r) {
            lazy[pos<<1] = lazy[pos<<1|1] = lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(v < l or u > r) return 0;
    if(u <= l and r <= v) return it[pos];
    int mid = (l + r) >> 1;
    return query(l,mid,u,v,pos<<1) + query(mid+1,r,u,v,pos<<1|1);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    scanf("%d",&test);
    FOR(t,1,test) {
        printf("Case %d:\n", t);
        scanf("%d%d",&n,&m);
        FOR(i,1,4*n) it[i] = lazy[i] = 0;
        FOR(i,1,n) scanf("%d", a+i);
        build(1,n,1);
        FOR(i,1,m) {
            int key,l,r; scanf("%d%d%d",&key,&l,&r);
            if(key == 1) {
                printf("%d\n", query(1,n,l,r,1));
                continue;
            }
            int val;
            scanf("%d",&val);
            update(1,n,l,r,val,1);
        }
    }
}
