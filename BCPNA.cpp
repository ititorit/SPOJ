// contest: http://www.spoj.com/PTIT/problems/BCPNA/
// author : Nguyen Minh Tuan
// lang   : C/C++

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>

#include <vector>
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

bool isPrime(int n) {
    int m = sqrt(n);
    FOR(i,2,m) if(!(n%i)) {return false;}
    return true;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("INPUT.inp", "r", stdin);
    #endif
    int test, n, cnt, s;
    cin >> test;
    while(test--) {
        cin >> n;
        cnt=0, s=0;
        if(isPrime(n)) cnt++;
        FOR(i,2,n/2) {
            s=0;
            if(isPrime(i)) {
                FOR(k,i,n) {
                    if(isPrime(k)) {
                        s += k;
                        if(s==n) cnt++;
                        else if(s>n) break;
                    }
                }
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}
