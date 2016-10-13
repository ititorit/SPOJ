// contest: http://www.spoj.com/PTIT/problems/BCMARA/
// author : Nguyen Minh Tuan
// lang   : C/C++

#include <algorithm>
#include <functional>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>

#define _for(i,a,b) for(int i=(a),_b_=(b),_d_=(a<b?1:-1);i!=_b_;i+=_d_)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define _it(i,v) for (typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define _all(v) v.begin(), v.end()

#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define sqr(x) ((x)*(x))
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

struct date {
    int h, m, s;
}a[5005];

bool cmp(const date& a, const date& b) {
  if (a.h == b.h) {
    if (a.m == b.m) return a.s < b.s;
    return a.m < b.m;
  }
  return a.h < b.h;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("INPUT.inp", "r", stdin);
    #endif

    // solution starts...
    
    int n;
    cin >> n;
    FOR(i,1,n) {
        cin >> a[i].h >> a[i].m >> a[i].s;
    }
    sort(a+1,a+1+n,cmp);
    FOR(i,1,n) {
        cout << a[i].h << ' ' << a[i].m << ' ' << a[i].s << '\n';
    }

    // solution end...
 
    return 0;
}
