// contest: http://www.spoj.com/PTIT/problems/SUMDIV/
// author : Nguyen Minh Tuan
// lang   : C/C++

#include <bits/stdc++.h>

#define _for(i,a,b) for(int i=(a),_b_=(b),_d_=(a<b?1:-1);i!=_b_;i+=_d_)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = a; i >= b; i--)
#define _it(i,v) for (typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define _all(v) v.begin(), v.end()

#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define sqr(x) ((x)*(x))
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("INPUT.inp", "r", stdin);
    #endif

    // solution starts....

    int n; cin >> n;
    ll x, s, sqrt_;
    while(n--) {
        cin >> x;
        if(x==1) {cout << 1 << '\n'; continue;}
        sqrt_ = sqrt(x);
        s = 1;
        for(int i = 2; i < sqrt(x); i++) {
            if(x%i==0) {s+=i+x/i;}
        }
        if((int)sqrt(x) == (float)sqrt(x)) {s += (int)sqrt(x);}
        cout << s + x << '\n';
    }

    // solution ends...

    return 0;
} 
