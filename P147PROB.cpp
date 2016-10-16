// Contest: http://www.spoj.com/PTIT/problems/P147PROB/

#include <bits/stdc++.h>
 
#define _for(i,a,b) for(int i=(a),_b_=(b),_d_=(a<b?1:-1);i<=_b_;i+=_d_)
#define _it(i,v) for (typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define _all(v) v.begin(), v.end()
 
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define sqr(x) ((x)*(x))
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("INPUT.inp", "r", stdin);
    #endif
    // solution starts...

    int n, per; float ans = 0;
    cin >> n;
    _for(i,1,n) {
        cin >> per;
        ans += (float)per;
    }
    printf("%.12f\n", ans/n);

    // solution ends...
 
    return 0;
}
