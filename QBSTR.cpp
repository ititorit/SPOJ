#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = a; i >= b; i--)
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
 
int LCS(string a, string b) {
	int m = a.size(), n = b.size();
	int L[m+1][n+1];
	FOR(i,0,m) FOR(j,0,n) {
		if(!i || !j) L[i][j] = 0;
		else if(a[i-1]==b[j-1]) L[i][j] = L[i-1][j-1]+1;
		else L[i][j] = max(L[i-1][j],L[i][j-1]);
	}
	return L[m][n];
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// solution starts...
	string a, b;
	cin >> a >> b;
	cout << LCS(a,b) << '\n';
	// solution ends...
	return 0;
}
 
