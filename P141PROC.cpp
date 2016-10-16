// contest: http://www.spoj.com/PTIT/problems/P141PROC/

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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("INPUT.inp", "r", stdin);
    #endif
    // solution starts...
    int test, ans = 0;
    cin >> test;
    string s;
    while(test--) {
        cin >> s;
        if(s=="++X") {ans += 1;}
        else if(s=="X++") {ans += 1;}
        else if(s=="--X") {ans -= 1;}
        else if(s=="X--") {ans -= 1;}
    }
    cout << ans << '\n';

    // solution ends...
 
    return 0;
}
