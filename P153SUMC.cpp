// contest: http://www.spoj.com/PTIT/problems/P153SUMC
// author : Nguyen Minh Tuan
// lang   : C/C++
// problem very very excited...

#include <algorithm>
#include <functional>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>

#define _for(i,a,b) for(int i=(a),_b_=(b),_d_=(a<b?1:-1);i!=_b_;i+=_d_)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
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

    #ifndef ONLINE_JUDGE
    freopen("INPUT.inp", "r", stdin);
    #endif
    int x, y, n;
    cin >> x >> y >> n;
    int ans;
    switch(n%6) {
        case 1: {ans = x;   break;}
        case 2: {ans = y;   break;}
        case 3: {ans = y-x; break;}
        case 4: {ans = -x;  break;}
        case 5: {ans = -y;  break;}
        case 0: {ans = x-y; break;}
    }
    cout << ans << '\n';
    // solution ends...

    return 0;
}
