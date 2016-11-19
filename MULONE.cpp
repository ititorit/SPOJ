#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
 
using namespace std;
 
const int   maxn = 1000001;
int         n,t,k;
char 		    s[2*maxn];
 
int main()
{
    cin >> t;
    while (t--) {
        scanf("%d",&n);
        k = 0;
        for (int i=1;i<2*n;i++) {
            if (i <= n) k += i;
            else k += 2*n-i;
            s[2*n-i] = k%10 + '0';
            k /= 10;
        }
        for (int i=1;i<2*n;i++) cout << s[i];
        cout << '\n';
    }
    return 0;
}
