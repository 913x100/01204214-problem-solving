#include <cstdio>
#include <vector>

using namespace std;

int a[100100], cnt=1;
vector<int> v[100100];

void dfs(int n)
{
    for(int i=0; i<v[n].size(); i++) {
        if(!a[v[n][i]]) {
            a[v[n][i]] = cnt;
            dfs(v[n][i]);
        }
    }
}

int main()
{
    int n,m,k, s, e;
    scanf("%d %d %d", &n, &m, &k);
    while(m--) {
        scanf("%d %d", &s, &e);
        v[s].push_back(e);
        v[e].push_back(s);
    }
    for(int i=1; i<=n; i++)
    {
        if(!a[i]) {
            a[i] = cnt;
            dfs(i);
            cnt++;
        }
    }
    while(k--) {
        scanf("%d %d", &s, &e);
        printf("%d\n", a[s]==a[e]);
    }
    return 0;
}
