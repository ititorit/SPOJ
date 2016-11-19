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
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// solution starts...
	int n;
	cin >> n;
	string s, word;
	getline(cin, s);
	while(n--) {
		int len(0),cnt(0),maxx(0);
		getline(cin, s);
		istringstream iss(s,istringstream::in);
		while(iss>>word) {
			if(word.length()==len) cnt++;
			else {
				len=word.length();
				cnt=1;
			}
			maxx=max(maxx,cnt);
		}
		cout << maxx << '\n';
	}
	// solution ends...
	return 0;
}
