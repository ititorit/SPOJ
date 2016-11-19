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

const ll _mod = 111539786;

struct matrix {
    ll x_1, y_1, x_2, y_2;
    matrix (ll a, ll b, ll c, ll d) {
        x_1 = a; y_1 = b;
        x_2 = c; y_2 = d;
    }
};

inline matrix multi(matrix a, matrix b) {
    ll x_1 = a.x_1*b.x_1+a.y_1*b.x_2;
    ll y_1 = a.x_1*b.y_1+a.y_1*b.y_2;
    ll x_2 = a.x_2*b.x_1+a.y_2*b.x_2;
    ll y_2 = a.x_2*b.y_1+a.y_2*b.y_2;
    return matrix(x_1 % _mod, y_1 % _mod, x_2 % _mod, y_2 % _mod);
}

inline matrix get_matrix(ll n) {
    if (n==1) return matrix(0, 1, 1, 1);
    matrix temp = get_matrix(n >> 1);
    if (n%2) return multi(temp, multi(temp, get_matrix(1)));
    return multi(temp, temp);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // solution starts... 

    int test, n;
    cin >> test;
    while(test--) {
    	cin >> n;
    	cout << get_matrix(n).y_2 << '\n';
    }

    // solution end...

    return 0;
}
