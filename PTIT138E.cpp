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
 
string process(string s) {
    int len = s.length();
    bool flag = false;
    FORD(i,len-1,1) {
        if(s[i] >= '5') {
            s[i] = '0';
            int temp = (int)s[i-1] - 48;
            if(temp == 9) {
                s[i-1] = '0';
                flag = true;
            } else {
                s[i-1] = (temp + 1) + '0';
            }
        } else {
            s[i] = '0';
        }
    }
    if(flag) {
        s = '1' + s;
    }
    return s;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    #ifndef ONLINE_JUDGE
    freopen("INPUT.inp", "r", stdin);
    #endif
    // solution starts...
    int test,len;
    string s;
    cin >> test;
    while(test--) {
        cin>>s;
        cout << process(s) << '\n';
    }
 
 
    // solution ends...
 
    return 0;
}
