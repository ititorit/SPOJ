#include <bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i = a; i <= b; i++)
#define _ford(i,a,b) for(int i = a; i >= b; i--)
#define _it(i,v) for (typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define _all(v) v.begin(), v.end()

#define pb push_back
#define mp make_pair
#define fi first
#define se second
 
#define DEBUG(x) { cout << "--> " << #x << " = " << x << '\n'; }
#define sqr(x) ((x)*(x))
#define reset(a,val) memset(a, val, sizeof(a))

#define INF         1011111111
#define EPS         (double)1e-8
#define mod         1000000007
#define PI          3.14159265358979

typedef long long ll;
typedef unsigned long long ull;

const int maxx = 200000;

int main() {
    // solution starts....
    int l, r, j;
    cin >> l >> r;
    bool prime[maxx+5];
    reset(prime, true)
    prime[1]=false;
    _for(i,2,maxx) {
        if(prime[i]) {
            j = 2*i;
            while(j<=maxx) {
                prime[i] = false;
                j+=i;
            }
        }
    }
    _for(i,l,r) {
        if(prime[i]) { cout << i << ' '; }
    }
    cout << '\n';
    // solution end....

    return 0;
}
