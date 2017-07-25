#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define v first
#define value second

const int MN = 1234;
vector< pair<int, int> > e[MN];
bool mark[MN];
int dis[MN];
queue<int> Q;
int s, t;

void bfs(int u) {
    Q.push(u);
    mark[u] = true;
    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (int i = 0; i < e[cur].size(); ++ i) {
            if(!mark[e[cur][i].v]) {
                Q.push(e[cur][i].v);
                mark[e[cur][i].v] = true;
                dis[e[cur][i].v] += (dis[cur] + e[cur][i].value);
            }
        }
    }
}

int main() {
    int n, q, u, v, l;
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; ++ i) {
        scanf("%d%d%d", &u, &v, &l);
        e[u].push_back(make_pair(v, l));
        e[v].push_back(make_pair(u, l));
    }
    while(q--) {
        scanf("%d%d", &s, &t);
        for (int i = 1; i <= n; ++ i) {
            mark[i] = false;
            dis[i] = 0;
        }
        while(!Q.empty()) Q.pop();
        bfs(s);
        printf("%d\n", dis[t]);
    }

    return 0;
}
