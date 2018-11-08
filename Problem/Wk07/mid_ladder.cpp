#include <cstdio>

int a[1010];

int main()
{
    int n, m, pos = 0, x;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
        scanf("%d", &a[i]);
    while(m--)
    {
        scanf("%d", &x);
        pos = pos + x + a[pos+x];
        if(pos < 1) pos = 0;
        if(pos > n) pos = n;
    }
    printf("%d\n", pos);
    return 0;
}
