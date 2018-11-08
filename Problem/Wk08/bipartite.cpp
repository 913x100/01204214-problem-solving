#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

bool bfs(vector<int> v[], int src, int a[])
{
    queue<int> q;
    a[src] = 1;
    q.push(src);

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        //printf("%d %d\n", u, a[u]);
        for(int i=0; i<v[u].size(); i++) {

            if(a[v[u][i]] == -1) {
                a[v[u][i]] = a[u] ^ 1;
                q.push(v[u][i]);
            }
            else if(a[u] == a[v[u][i]])
                return false;
        }
    }
    return true;
}

bool isBipartite()
{
    int a[100100];
    memset(a, -1, sizeof(a));
    vector<int> v[100100];
    int n, m, s, e;
    scanf("%d %d", &n, &m);
    while(m--) {
        scanf("%d %d", &s, &e);
        v[s].push_back(e);
        v[e].push_back(s);
    }

    for(int i=1; i<=n; i++) {
        if(a[i] == -1) {
            if(!bfs(v, i, a))
                return false;
        }
    }
    return true;
}

int main()
{
    int k;
    scanf("%d", &k);

    while(k--) {
        printf("%s\n", (isBipartite())?"yes":"no");
    }
    return 0;
}

