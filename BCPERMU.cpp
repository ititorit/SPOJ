#include <bits/stdc++.h>

#define _for(i,a,b) for(int i=(a),_b_=(b),_d_=(a<b?1:-1);i!=_b_;i+=_d_)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = a; i >= b; i--)
#define _it(i,v) for (typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define _all(v) v.begin(), v.end()

#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define sqr(x) ((x)*(x))
 
using namespace std;
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;

int a[10], flag[10], n;

void Try(int index) {
	FOR(i,1,n) {
		if(flag[i]==false) {
			a[index] = i;
			flag[i] = true;
			if(index==n) {
				FOR(j,1,n) cout << a[j];
				cout << '\n';
			} else Try(index+1);
			flag[i] = false;
		}
	}
}

int main(){
	  ios_base::sync_with_stdio(0);
	  cin.tie(0);

	  #ifndef ONLINE_JUDGE
    freopen("INPUT.inp", "r", stdin);
    #endif

    // solution starts...

    
    cin >> n;
    FOR(i,1,n) {
    	flag[i] = false;
    	a[i] = i;
    }
    Try(1);

    // solution ends...
    return 0;
}
