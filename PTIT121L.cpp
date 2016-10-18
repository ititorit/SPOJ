// Contest: http://www.spoj.com/PTIT/problems/PTIT121L/

#include <bits/stdc++.h>
 
#define _for(i,a,b) for(int i=(a),_b_=(b),_d_=(a<b?1:-1);i<=_b_;i+=_d_)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define _it(i,v) for (typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define _all(v) v.begin(), v.end()
 
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define sqr(x) ((x)*(x))
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll max6(ll a, ll b, ll c, ll d, ll e, ll f) {
    return max( max( max(a,b), max(c, d) ), max(e, f) );
}

struct hcn {
    ll x, y;
};

bool cmp(const hcn& a, const hcn& b) {return (a.x < b.x);}

bool binarySearch(ll a[], int n, ll val) {
    int l = 1, r = n, m;
    while(l<=r) {
        m = (l+r)>>1;
        if(a[m]==val) return true;
        else if(val > a[m]) l=m+1;
        else r=m-1;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("INPUT.inp", "r", stdin);
    #endif
    // solution starts...

    hcn a[4];
    FOR(i,1,3) {
        cin >> a[i].x >> a[i].y;
        if(a[i].x > a[i].y) {
            swap(a[i].x, a[i].y);
        }
    }
    sort(a+1,a+4,cmp);
    // FOR(i,1,3) {
    //     cout << a[i].x << ' ' << a[i].y << endl;
    // }
    // return 0;

    ll maxx = max6(a[1].x,a[2].x,a[3].x,a[1].y,a[2].y,a[3].y);
    int cnt=0;
    FOR(i,1,3) {
        if(a[i].y==maxx) cnt++;
    }

    if(cnt==2) {
        cout << "0\n";
        return 0;
    }
    if(cnt==3) {
        if(a[1].x+a[2].x+a[3].x==maxx) {
            cout << maxx << '\n';
            return 0;
        } else {
            cout << "0\n";
            return 0;
        }
    }
    ll temp[7];
    temp[1] = a[1].x;
    temp[2] = a[1].y;
    temp[3] = a[2].x;
    temp[4] = a[2].y;
    temp[5] = a[3].x;
    sort(temp+1,temp+6);
    cnt=0;
    FOR(i,1,3) {
        if(!binarySearch(temp,6,maxx-a[i].x)) {
            cout << "0\n";
            return 0;
        }
    }
    cout << maxx << '\n';
    // solution ends...
 
    return 0;
}
