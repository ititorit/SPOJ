// contest: http://www.spoj.com/PTIT/problems/BCTELEPH/
// author : Nguyen Minh Tuan
// lang   : C/C++

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
typedef unsigned long long ull;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// solution starts...

	int test, a, leng;
	string s;
	cin >> test;
	while(test--) {
		cin >> a >> s;
		leng = s.length();
		int vt = 0;
		FORD(i,leng-2,0) {
			if(s[i] < s[i+1]) {
				vt = i;
				break;
			}
		}
		if(vt == 0) {
			cout << a << ' ' << "BIGGEST\n";
			continue;
		} else {
			int temp;
			int i = leng - 1;
			while(i >= vt && s[i] <= s[vt]) {
				i--;
			}
			temp = i;
			swap(s[temp], s[vt]);
			cout << a << ' ';
			FOR(i,0,vt) cout << s[i];
			FORD(i,leng-1,vt+1) cout << s[i];
			cout << '\n';
		}
	}

	// solution ends...

	return 0;
}
