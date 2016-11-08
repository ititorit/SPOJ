// Contest: vn.spoj.com/problems/NKABD/
// Author : Nguyen Minh Tuan
// Lang   : C/C++


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

bool f(int n) {
	int s=1, l=(int)sqrt(n);
	_for(i,2,l) {
		if(n%i==0) {
			s += i;
			if(i!=(n/i)) s += n/i;
			if(s>n) return true;
		}
	}
	return (s > n);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// solution starts...
	int l, r,cnt(0);
	cin >> l >> r;
	_for(i,l,r) {
		if(f(i)){ cnt++; }
	}
	cout << cnt << '\n';
	
	// solution ends...
	return 0;
}
