// contest: http://www.spoj.com/PTIT/problems/PTIT127G/
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

struct cmp {
    bool operator() (const std::string& lhs, const std::string& rhs) {
        size_t l_sz = lhs.size();
        size_t r_sz = rhs.size();
        if (l_sz < r_sz) return 1;
        if (l_sz > r_sz) return 0;
        for (size_t i = 0; i < l_sz; ++i) {
            if (lhs[i] < rhs[i]) return 1;
            if (lhs[i] > rhs[i]) return 0;
        }
        return 0;
    }
};
 
multiset<string, cmp> ms;
string str;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("INPUT.inp", "r", stdin);
    #endif

    int n;
    std::cin >> n;
    while (n--) {
        cin >> str;
        str += 'a';
        size_t sz = str.size();
        size_t it = 0;
        std::string buffer;
        while (it < sz) {
            if (isdigit(str[it])) {
                if (buffer.size() && buffer[0] == '0') {
                    buffer[buffer.size() - 1] = str[it];
                } else {
                    buffer += str[it];
                }
            } else {
                if (buffer.size()) {
                    ms.insert(buffer);
                    buffer.clear();
                }
            }
            ++it;
        }    
    }
    for (__typeof(ms.begin()) i = ms.begin(); i != ms.end(); ++i) {
        cout << *i << '\n';
    }
} 
