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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    sort(_all(s));
    int a[26];
    reset(a, 0);
    int len = s.length(), res(1);
    _for(i,0,len-1) {
        a[s[i]-'A']++;
    }
    _for(i,0,len-1) {
        res *= i+1;
    }
    _for(j,0,25) {
        _for(i,0,a[j]-1) {
            res /= i+1;
        }
    }
    cout << res << '\n';
    
    do {
        cout << s << '\n';
    } while(next_permutation(_all(s)));
    return 0;
}
