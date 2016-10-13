// contest: http://www.spoj.com/PTIT/problems/BCTOHOP/
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

void next(int a[], int n, int k, bool& flag) {
    int i = k;
    while(i >= 0 && a[i] == n - k + i) i--;
    if(i > 0) {
        a[i]++;
        FOR(j,i+1,k) a[j] = a[j-1]+1;
    } else {
        flag = true;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("INPUT.inp", "r", stdin);
    #endif

    // solution starts...
    int a[100], n, k;
    cin >> n >> k;
    bool flag = false;
    FOR(i,1,k) a[i] = i;
    while(flag == false) {
        FOR(i,1,k) cout << a[i] << ' ';
        cout << '\n';
        next(a, n, k, flag);
    }

    // solution ends...

    return 0;
}
