// contest: http://vn.spoj.com/problems/QBMAX/

#include <bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i = a; i <= b; i++)
#define _ford(i,a,b) for(int i = a; i >= b; i--)
#define _it(i,v) for (typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define _all(v) v.begin(), v.end()

#define pb push_back
#define mp make_pair
#define fi first
#define se second
 
#define DEBUG(x) { cout << "--> " << #x << " = " << x << '\n'; }
#define sqr(x) ((x)*(x))
#define reset(a,val) memset(a, val, sizeof(a))

#define INF         1011111111
#define EPS         (double)1e-8
#define mod         1000000007
#define PI          3.14159265358979

typedef long long ll;
typedef unsigned long long ull;

ll _max(ll a, ll b, ll c) {
    return max(max(a,b),c);
}

int a[105][105];
const int oo = 100000;

int main() {

    // solution starts....
    int m, n;
    cin >> m >> n;
    _for(i,0,m+1)_for(j,0,n+1) {
        a[i][j] = -oo;
    }
    _for(i,1,m) _for(j,1,n) cin >> a[i][j];
    _for(j,2,n) {
        _for(i,1,m) {
            a[i][j] += _max(a[i-1][j-1],a[i][j-1],a[i+1][j-1]);
        }
    }

    int ans = a[1][n];
    _for(i,2,m) {
        if(ans < a[i][n]) {
            ans = a[i][n];
        }
    }
    cout << ans << '\n';

    // solution end....

    return 0;
}
