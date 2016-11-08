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
 
ll gcd(ll a, ll b) {
	if(a < 0) return gcd(-a,b);
	if(b < 0) return gcd(a,-b);
	return (b?gcd(b,a%b):a);
}
 
ll rev(ll a) {
	ll s(0);
	while(a) {
		s=10*s+(a%10);
		a/=10;
	}
	return s;
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// solution starts...
	int l, r, cnt(0);
	cin >> l >> r;
	_for(i,l,r) {
		if(gcd(i,rev(i))==1) cnt++;
	}
	cout << cnt << '\n';
	
	// solution ends...
	return 0;
}
