// contest: http://www.spoj.com/PTIT/problems/YOUNGCLA/
// author : Nguyen Minh Tuan (ititorit)
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

struct Info {
    string name;
    int dd, mm, yyyy;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("INPUT.inp", "r", stdin);
    #endif

    // solution starts....
    Info a[101];
    int n; cin >> n;
    ll temp[101];
    FOR(i,1,n) {
        cin >> a[i].name >> a[i].dd >> a[i].mm >> a[i].yyyy;
        temp[i] = a[i].dd + (a[i].mm)*30 + 365*(a[i].yyyy);
    }
    ll maxx = 0;
    ll minn = 1e9;
    int min_vt, max_vt;
    FOR(i,1,n) {
        if(temp[i] < minn) {
            minn = temp[i];
            min_vt = i;
        }
        if(temp[i] > maxx) {
            maxx = temp[i];
            max_vt = i;
        }
    }
    cout << a[max_vt].name << '\n' << a[min_vt].name << '\n';

    // solution ends...

    return 0;
}
