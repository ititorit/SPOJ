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

int main() {

    // solution starts....
    ll n;
    cin >> n;
    if(n==1) {
        cout << "3\n1 2 3\n";
        return 0;
    }
    if(n==2) {
        cout << "1\n4\n";
        return 0;
    }
    if(n==3) {
        cout << "2\n5 6\n";
        return 0;
    }
    ll i = 2;
    double ans(0);
    n--;
    while(true) {
        ans += log10(i);
        if(n == (int)ans) {
            cout << "1\n" << i << '\n';
            return 0;
        }
        if((int)ans > n) {
            cout << "NO\n";
            return 0;
        }
        i++;
    }
    // solution end....

    return 0;
}
