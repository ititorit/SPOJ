// Contest: http://www.spoj.com/PTIT/problems/P155PROB/

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
 
    int x, s, temp;
    cin >> x >> s;
    int cur = x*s;
    _for(i,1,5) {
        cin >> temp;
        cout << temp - cur << ' ';
    }
 
    // solution ends...
 
    return 0;
} 
