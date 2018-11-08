#include <cstdio>
#include <vector>

using namespace std;

vector<int> a[1010];
int mark[1010], cnt=1;
bool res = false;

void dfs(int u)
{
    mark[u] = cnt;
    for(int i=0; i<a[u].size(); i++)
    {
        if(mark[a[u][i]] != cnt)
            dfs(a[u][i]);
        else
            res = true;

    }
}

void solve()
{
    int n, u, m;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        a[i].clear();
        scanf("%d", &m);
        for(int j=0; j<m; j++)
        {
            scanf("%d", &u);
            a[i].push_back(u);
        }
    }
    res = false;
    for(int i=1; i<=n; i++)
    {
        dfs(i);
        cnt++;
    }
    printf("%s\n", (res)?"Yes":"No");
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int t=0; t<T; t++)
    {
        printf("Case #%d: ", t+1);
        solve();

    }


    return 0;
}
