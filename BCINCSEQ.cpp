// contest: http://www.spoj.com/PTIT/problems/BCINCSEQ/
// author : Nguyen Minh Tuan
// lang   : C/C++
// algo   : Dynamic Programming

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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // solution starts...

    #ifndef ONLINE_JUDGE
    freopen("INPUT.inp", "r", stdin);
    #endif
    int n, a[100005], dp[100005], ans=0;
    cin >> n;
    FOR(i,1,n) cin >> a[i];
    a[0]=1000000000;
    dp[0]=0;
    FOR(i,1,n) {
        if(a[i] >= a[i-1]) {
            dp[i]=dp[i-1]+1;
        } else {
            dp[i]=1;
        }
    }
    FOR(i,1,n) {
        if(dp[i] > ans) ans=dp[i];
    }
    cout << ans << '\n';
    // solution ends...

    return 0;
}
