// Contest: http://www.spoj.com/PTIT/problems/P132SUMJ/

#include <bits/stdc++.h>
using namespace std;

#define _for(i,a,b) for(int i=(a),_b_=(b),_d_=(a<b?1:-1);i<=_b_;i+=_d_)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = a; i >= b; i--)
#define _it(i,v) for (typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define _all(v) v.begin(), v.end()

#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define sqr(x) ((x)*(x))
 
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

    string s;
    cin >> s;
    int len = s.length(), vt = -1;
    FORD(i,len-2,0) {
        if(s[i] < s[i+1]) {
            vt = i;
            break;
        }
    }
    if(vt==-1) {
        cout << 0 << '\n';
        return 0;
    }

    FORD(i,len-1,vt+1) {
        if(s[i] > s[vt]) {
            swap(s[i], s[vt]);
            FOR(j,vt+1,len-2) FOR(k,j+1,len-1) {
                if(s[j] > s[k]) {
                    swap(s[j], s[k]);
                }
            }
            break;
        }
    }
    cout << s << '\n';

    // solution ends...
 
    return 0;
}
