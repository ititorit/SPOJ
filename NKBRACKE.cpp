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
 
int n, m, it[MN << 2], a[MN], lazy[MN<<2];
char temp[MN];
 
void build(int l, int r, int pos) {
    if(l == r) {
        it[pos] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,pos<<1);
    build(mid+1,r,pos<<1|1);
    it[pos] = min(it[pos<<1], it[pos<<1|1]);
    return;
}
 
void update(int l, int r, int u, int v, int val, int pos) {
    if(l > r) return;
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
        it[pos] += val;
        if(l != r) {
            lazy[pos<<1] += val;
            lazy[pos<<1|1] += val;
        }
        return;
    }
    int mid = (l + r) >> 1;
    update(l,mid,u,v,val,pos<<1);
    update(mid+1,r,u,v,val,pos<<1|1);
    it[pos] = min(it[pos<<1],it[pos<<1|1]);
    return;
}
 
int query(int l, int r, int u, int v, int pos) {
    if(l > r) return inf;
    if(lazy[pos] != 0) {
        it[pos] += lazy[pos];
        if(l != r) {
            lazy[pos<<1] += lazy[pos];
            lazy[pos<<1|1] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(u == 0) return 0;
    if(v < l or u > r) return inf;
    if(u <= l and r <= v) return it[pos];
    int mid = (l + r) >> 1;
    return min(query(l,mid,u,v,pos<<1),
            query(mid+1,r,u,v,pos<<1|1));
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    scanf("%d%d%s",&n,&m,temp);
    REP(i,n) {
        if(temp[i] == '(') a[i+1] = a[i] + 1;
        else a[i+1] = a[i] - 1;
    }
    build(1,n,1);
    FOR(i,1,m) { // each query
        int key; scanf("%d",&key);
        if(key == 1) {
            int l, r; 
            scanf("%d%d",&l,&r);
            int aR   = query(1,n,r,r,1);
            int aL1  = query(1,n,l-1,l-1,1);
            int mnLR = query(1,n,l,r,1);
            if(aR == aL1 and mnLR == aL1) {
                printf("1");
            } else {
                printf("0");
            }
        } else {
            int idx; char x[9];
            scanf("%d%s",&idx,x);
            if(temp[idx-1] == '(' and x[0] == ')') {
                update(1,n,idx,n,-2,1);
                temp[idx-1] = ')';
            } else if(temp[idx-1] == ')' and x[0] == '(') {
                update(1,n,idx,n, 2,1);
                temp[idx-1] = '(';
            }
        }
    }
    puts("");
} 
