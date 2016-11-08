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
#define mem(a,val) memset(a, val, sizeof(a))

#define INF         1011111111
#define EPS         (double)1e-8
#define mod         1000000007
#define PI          3.14159265358979

typedef long long ll;
typedef unsigned long long ull;

ll n, a[100005], b[100005], oo=3000000000;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// solution starts...

	cin >> n;
	_for(i,1,n) cin >> a[i]; 
	_for(i,1,n) cin >> b[i];
	ll min=oo;
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	ll i = 1, j = n, k;
	while(i <= n && j > 0) {
		k = a[i] + b[j];
		if(k==0) { cout << 0 << '\n'; return 0; }
		if(abs(k) < min){ min = abs(k); }
		if(k < 0){ i++; }
		else{ j--; }
	}
	cout << min << '\n';
	
	// solution ends...
	return 0;
}
