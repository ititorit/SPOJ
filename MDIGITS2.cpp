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
#define reset(a,val) memset(a, val, sizeof(a))

#define INF         1011111111
#define EPS         (double)1e-8
#define mod         1000000007
#define PI          3.14159265358979

typedef long long ll;
typedef unsigned long long ull;

inline int strToInt(string s) {
    return atoi(s.c_str());
}

inline string convertInt(int number) {
   stringstream ss;
   ss << number;
   return ss.str();
}

// KMP algorithm
int KMP(string s, string t) {
    int n = s.length(), m = t.length();
    int* pit = new int[m+1];
    if(m >= 0) pit[0] = 0;
    if(m >= 1) pit[1] = 0;
    _for(i, 2, m) {
        for(int j = pit[i-1]; ;j = pit[j]) {
            if(t[j] == t[i-1]) { pit[i] = j + 1; break; }
            if(j == 0) { pit[i] = 0; break; }
        }
    }
    for(int i = 0, j = 0; i < n; ) {
        if(s[i] == t[j]) {
            i++; j++;
            if(j == m) return i - m;
        } else if(j > 0) {
            j = pit[j];
        } else i++;
    } delete[] pit; return -1;
}

string s;

void init() {
    s.clear();
    _for(i,1,100000) { s += convertInt(i); }
}

int main() {

    // solution starts....
    init();
    int n; cin >> n;
    cout << KMP(s, convertInt(n)) + 1 << '\n';
    // solution end....

    return 0;
}
