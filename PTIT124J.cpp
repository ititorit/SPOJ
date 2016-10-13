// contest: http://www.spoj.com/PTIT/problems/PTIT124J/
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

// 000   =    0    ---     100  =  4
// 001   =    1    ---     101  =  5         
// 010   =    2    ---     110  =  6
// 011   =    3    ---     111  =  7

int check1(string s) {
	if(s == "000") return 0;
	if(s == "001") return 1;
	if(s == "010") return 2;
	if(s == "011") return 3;
	if(s == "100") return 4;
	if(s == "101") return 5;
	if(s == "110") return 6;
	if(s == "111") return 7;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	  #ifndef ONLINE_JUDGE
    freopen("INPUT.inp", "r", stdin);
    #endif

	  string s;
	  cin >> s;

    int leng = s.length();
    if(leng%3 != 0) {
    	if(leng%3==1) {
    		s.insert(0,2,'0');
    	} else if(leng%3==2) {
    		s.insert(0,1,'0');
    	}
    }
    
    leng = s.length();
    while(leng) {
    	string cur="";
    	FOR(i,0,2) {
    		cur += s[i];
    	}

    	cout << check1(cur);
    	s.erase(0,3);
    	leng -= 3;
    }

    // solution ends...
    return 0;
}
