#include <bits/stdc++.h>
using namespace std;

#define ll long long 

const int MN = 2222;
vector<int> e[MN];
bool mark[MN];
stack<int> s;

void dfs(int u) {
    s.push(u);
    mark[u] = true;
    while(!s.empty()) {
        int cur = s.top();
        s.pop();
        for (int i = 0; i < e[cur].size(); ++ i) {
            if(!mark[e[cur][i]]) {
                s.push(e[cur][i]);
                mark[e[cur][i]] = true;
            }
        }
    }
}

int main() {
    int n, m;
    int u, v;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++ i) {
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1);
    int d = 1;
    for (int i = 1; i <= n; ++ i) {
        if(!mark[i]) {
            ++ d;
            dfs(i);
        }
    }
    printf("%d\n", m - n + d);

    return 0;
}
