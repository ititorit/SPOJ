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

const int MAX = 500000;

ll a[MAX+1];
std::set<ll> gr;
void init() {
    _for(i,1,500000) {
        if(a[i-1] - i > 0 && gr.find(a[i-1]-i) == gr.end()) {
            a[i] = a[i-1] - i;
        } else a[i] = a[i-1] + i;
        gr.insert(a[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // solution starts...
    init();
    while(cin >> n && n != -1) {
        cout << a[n] << '\n';
    }
    // solution end....

    return 0;
}
