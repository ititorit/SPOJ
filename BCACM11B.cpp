// Contest: http://www.spoj.com/PTIT/problems/BCACM11B/

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

    int test, a[105][105], n, x, y;
    cin >> test;

    while(test--) {
        cin >> n >> x >> y;

        memset(a, 0, sizeof a);

        int val=0, up=1,down=n,left=1,right=n;
        do {
            FOR(i,left,right) {
                val++;
                a[up][i]=val;
            }
            up++;
            FOR(i,up,down) {
                val++;
                a[i][right]=val;
            }
            right--;
            FORD(i,right,left) {
                val++;
                a[down][i]=val;
            }
            down--;
            FORD(i,down,up) {
                val++;
                a[i][left]=val;
            }
            left++;
        }while(val!=sqr(n));

        cout << a[x][y] << '\n';
    }

    // solution ends...
 
    return 0;
}
