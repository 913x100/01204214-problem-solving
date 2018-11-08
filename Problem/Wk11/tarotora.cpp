#include <cstdio>
#include <cstring>

int min(int a,int b)
{
    return (a<b)?a:b;
}

int dp[2][210];

int main()
{
    int n, k, a, b, t;
    scanf("%d %d", &n, &k);

    int flag = 1;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=205; j++)
            dp[flag][j] = 1<<31-1;
        scanf("%d %d", &a, &b);
        for(int j=0; j<=2*k; j++)
        {
            t = dp[flag][j];
            if(j<2*k) t = max(t, dp[!flag][j+1]+a);
            if(j>0) t = max(t, dp[!flag][j-1]+b);
            dp[flag][j] = t;

            //printf("%d\n", t);
        }
        flag = !flag;
    }
    flag = !flag;
    for(int i=100-k; i<=100+k; i++)
        printf("%d ", dp[flag][i]);

    int res = 1<<31-1;
    for(int i=1; i<2*k; i++)
        res = min(res, dp[flag][i]);
    printf("%d\n", res);
    //printf("%d\n", min(dp[flag][k-1], min(dp[flag][k], dp[flag][k+1])));
    return 0;
}
