#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i, a, b)        for(int i = a; i <= b; i++)
#define FORD(i, a, b)	    for(int i = a; i <  b; i++)
#define REP(i, a, b)	    for(int i = a; i >= b; i--)
#define REPD(i, a, b)	    for(int i = a; i >  b; i--)
 
#define DEBUG(x)	    { cout << #x << " = " << x << endl; }
#define sqr(x)		    x * x
 
#define ull		    unsigned long long
#define ll		    long long
 
int N, h[30005], A[30005], res = 1, Left, Right, Mid;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	// solution starts...
	cin >> N;
	FOR(i,1,N) cin >> A[i];
	h[1] = 1;
	FOR(i,2,N) {
		if(A[i] < A[h[1]]) {
			h[1] = i;
		}
		else {
			if(A[i] > A[h[res]]) {
				res++;
				h[res] = i;
			}
			else {
				Left = 1, Right = res, Mid;
				while(Left <= Right) {
					Mid = (Left + Right) >> 1;
					if(A[i] > A[h[Mid]]) {
						Left = Mid + 1;
					} else Right = Mid - 1;
				}
				h[Left] = i;
			}
		}
	}
	cout << res << endl;
	// solution end...
 
	return 0;
} 
