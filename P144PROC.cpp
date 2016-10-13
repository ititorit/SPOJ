// contest: http://www.spoj.com/PTIT/problems/P144PROC/
// author : Nguyen Minh Tuan (ititorit)
// lang   : C/C++

#include <bits/stdc++.h>

#define _for(i,a,b) for(int i=(a),_b_=(b),_d_=(a<b?1:-1);i!=_b_;i+=_d_)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = a, i >= b; i--)
#define _it(i,v) for (typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define _all(v) v.begin(), v.end()

#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define sqr(x) ((x)*(x))

 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1e9+7;

// power modulo algorithm
ll power_modulo(ll a, ll b, ll mod) {
    if(!b) return 1;
    if(!(b%2)) {
        ll t = pow_mod(a,b/2);
        return (sqr(t))%mod;
    }
    return (a*pow_mod(a,b-1))%mod;
}
// end power modulo

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("INPUT.inp", "r", stdin);
    #endif

    // solution starts...
    ll a, b; 

    while(true) {
        cin >> a >> b;
        if(!a && !b) return 0;
        ll temp = pow_mod(a, b, mod);
        cout << temp << '\n';
    }
    // solution ends...

    return 0;
}
