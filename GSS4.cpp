// author: ititorit (Rentt)
// Link  : http://www.spoj.com/problems/GSS4/
// Algo  : Segment Tree + Update offline
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

const ll MN = 1e5+5;
ll n, m, a[MN], l, r;

struct Node {
    ll sum; bool flag;
    Node() {
        sum = 0;
        flag = false;
    }
    void merge(Node l, Node r) {
        sum = l.sum + r.sum;
        flag = (l.flag and r.flag) ? true : false;
    }
} it[MN << 2];

void build(int l, int r, int pos) {
    if(l == r) {
        it[pos].sum = a[l];
        if(a[l] == 1) it[pos].flag = true;
        else it[pos].flag = false;
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,pos<<1); 
    build(mid+1,r,pos<<1|1);
    it[pos].merge(it[pos<<1],it[pos<<1|1]);
    return;
}

void update(int l, int r, int u, int v, int pos) {
    if(v < l or u > r) return; // no overlap
    if(it[pos].flag == true) return; // val = 1 so we don't update
    if(l == r) { // is a leaf node -> we update.
        a[l] = (int)sqrt(a[l]);
        it[pos].sum = a[l];
        if(a[l] == 1) it[pos].flag = true;
        return;
    }
    // call recursive update for left child and right child
    int mid = (l + r) >> 1;
    if(mid >= r)     update(l,mid,u,v,pos<<1);
    else if(mid < l) update(mid+1,r,u,v,pos<<1|1);
    else {
        update(l,mid,u,v,pos<<1);
        update(mid+1,r,u,v,pos<<1|1);
    }
    it[pos].merge(it[pos<<1],it[pos<<1|1]);
    return;
}

ll query(int l, int r, int u, int v, int pos) {
    if(v < l or u > r) return 0;
    if(u <= l and r <= v) return it[pos].sum;
    int mid = (l + r) >> 1;
    return query(l,mid,u,v,pos<<1) + query(mid+1,r,u,v,pos<<1|1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test = 0;
    while(scanf("%lld",&n) != EOF) {
        FOR(i,1,4*n) {
            it[i] = Node();
        }
        printf("Case #%d:\n",++test);
        FOR(i,1,n) scanf("%lld",&a[i]);
        build(1,n,1);
        scanf("%lld",&m);
        FOR(i,1,m) {
            int key;
            scanf("%d%lld%lld",&key, &l, &r);
            if(l > r) swap(l,r);
            if(key == 1) {
                printf("%lld\n", query(1,n,l,r,1));
                continue;
            }
            update(1,n,l,r,1);
        }
        printf("\n");
    }
}
