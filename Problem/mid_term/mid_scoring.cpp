#include <cstdio>

int exam[110], mark[110];

int main()
{
    int n, m, a, s;
    scanf("%d %d", &n, &m);
    while(m--) {
        scanf("%d %d", &a, &s);
        mark[a]++;
        if(mark[a] > 5)
            exam[a] = 0;
        else
            exam[a] = (s > exam[a])?s:exam[a];
    }

    int res = 0;
    for(int i=1; i<=n; i++)
        res += exam[i];
    printf("%d\n", res);
    return 0;
}
