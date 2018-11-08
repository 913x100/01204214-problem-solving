#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct node{
    int u, v;
};
node inp[100100];

vector<int> e[100100];
queue<int> q;
int mark[100100];
int n, m, res = 0;

bool bfs(int x)
{
    //printf("y");
    mark[x] = 0;
    q.push(x);

    while(!q.empty())
    {
        int u = q.front();
        //printf("u%d\n", u);
        q.pop();
        for(int i=0; i<e[u].size(); i++)
        {
            int v = e[u][i];

            if(mark[u] == mark[v]) return false;
            if(mark[v] != -1) continue;

            mark[v] = !mark[u];
            q.push(v);
        }
    }
    return true;
}

void solve(int lo, int hi)
{
    int mid = (lo+hi)/2;

    if(lo>hi) return ;

    for(int i=1; i<=n; i++)
        e[i].clear();
    for(int i=1; i<=n; i++)
        mark[i] = -1;

    for(int i=1; i<=mid; i++)
    {
        int u = inp[i].u;
        int v = inp[i].v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    bool check = true;
    for(int i=1; i<=n; i++) {
        if(mark[i] == -1)
            check &= bfs(i);
    }
    if(!check)
        solve(lo, mid-1);
    else
    {
        res = mid;
        solve(mid+1, hi);
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    for(int i=1; i<=m; i++)
        scanf("%d %d", &inp[i].u, &inp[i].v);
    solve(1, m);

    printf("%d\n", res);

    return 0;
}
