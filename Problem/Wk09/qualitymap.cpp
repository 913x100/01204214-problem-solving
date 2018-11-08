#include <cstdio>
#include <queue>

using namespace std;

int n, m, t1, t2, cnt;
char a[35][35];

void check(int i, int j)
{
    if(a[i][j] == '*')
            t1 = 1;
    if(a[i][j] == '$')
            t2 = 1;
    a[i][j] = '#';
}

void DFS(int i, int j)
{
    cnt++;
    if(i+1<n && a[i+1][j]!='#')
    {
        check(i+1, j);
        DFS(i+1, j);
    }
    if(i-1>=0 && a[i-1][j]!='#')
    {
        check(i-1, j);
        DFS(i-1, j);
    }
    if(j+1<m && a[i][j+1]!='#')
    {
        check(i, j+1);
        DFS(i, j+1);
    }
    if(j-1>=0 && a[i][j-1]!='#')
    {
        check(i, j-1);
        DFS(i, j-1);
    }
}

int main()
{
    int res1=0, res2=0;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf(" %c", &a[i][j]);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(a[i][j] != '#')
            {
                t1 = t2 = cnt = 0;
                check(i, j);
                DFS(i, j);
                if(t1 + t2 == 2)
                    res1 += cnt;
                else if(t1 + t2 == 1)
                    res2 += cnt;
            }
        }
    }
    printf("%d %d\n", res1, res2);
    return 0;
}
