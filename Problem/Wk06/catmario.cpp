#include <cstdio>

int a[110];

int main()
{
    int n, m, i, t;
    scanf("%d %d", &n, &m);
    while(m--) {
        scanf("%d %d", &i, &t);
        if(a[i] == 0)
            a[i] = t;
        else
            a[i] = (t < a[i])?t:a[i];
    }
    int res = 0;
    for(int i=1; i<=n; i++)
        res += a[i];
    printf("%d\n", res);
    for(int i=1; i<=n; i++)
        printf("%d %d\n", i, a[i]);
    return 0;
}
