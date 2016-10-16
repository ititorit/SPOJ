// Contest: http://www.spoj.com/PTIT/problems/P155PROF/

#include <bits/stdc++.h>
 
#define _for(i,a,b) for(int i=(a),_b_=(b),_d_=(a<b?1:-1);i<=_b_;i+=_d_)
#define _it(i,v) for (typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define _all(v) v.begin(), v.end()
 
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define sqr(x) ((x)*(x))
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("INPUT.inp", "r", stdin);
    #endif
    // solution starts...

    ll x, y, n, ans;
    cin >> x >> y >> n;

    switch(n%6) {
        case 1: { ans = x;   break; }
        case 2: { ans = y;   break; }
        case 3: { ans = y-x; break; }
        case 4: { ans = -x;  break; }
        case 5: { ans = -y;  break; }
        case 0: { ans = x-y; break; }
    }
    if(ans < 0) {
        ans += mod;
    }
    cout << ans << '\n';
    // solution ends...
 
    return 0;
}
