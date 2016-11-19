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
const int _mod = 111539786;
 
map<ll, ll> a;
 
ll fibonacci(ll n) {
    if (a[n] != 0) return a[n];
	ll k = (n>>1);
	if ( n%2 == 0 )  {
		return a[n] = (fibonacci(k) * fibonacci(k) + fibonacci(k-1) * fibonacci(k-1)) % _mod;
	} 
	return a[n] = (fibonacci(k) * fibonacci(k+1) + fibonacci(k-1) * fibonacci(k)) % _mod;
}
 
 
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    // solution starts....
  	ll n, test;
  	cin >> test;
  	a[0] = 1, a[1] = 1;
    while(test--) {
    	cin >> n;
    	cout << fibonacci(n) % _mod << '\n';
    }
    
    // solution end....
 
    return 0;
}
