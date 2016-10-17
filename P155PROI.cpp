// Contest: http://www.spoj.com/PTIT/problems/P155PROI/

#include <bits/stdc++.h>
 
#define _for(i,a,b) for(int i=(a),_b_=(b),_d_=(a<b?1:-1);i<=_b_;i+=_d_)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
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
    int n;
    cin >> n;
    int cnt[1001], a[101], b[101];
    memset(cnt, 0, sizeof(cnt));
    FOR(i,1,n) {
        cin >> a[i] >> b[i];
        cnt[b[i]]++;
    }
    int ans = 0;
    FOR(i,1,n) {
        if(cnt[a[i]] == 0) {
            ans++;
        }
        if((a[i]==b[i]) && (cnt[a[i]] == 1)) {
            ans++;
        }
    }
    cout << ans << '\n';
    // solution ends...
 
    return 0;
}
