#include <cstdio>

int min(int a, int b)
{
    return (a<b)?a:b;
}

int n, m;
int dp[505][505];

int main()
{
    int T;
    scanf("%d", &T);
    for(int i=1; i<=500; i++)
        dp[i][0] = 1<<30;
    for(int t=0; t<T; t++) {
        scanf("%d %d", &m, &n);

        for(int i=0; i<=m; i++)
            dp[i][n+1] = 1<<30;

        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                scanf("%d", &dp[i][j]);

                int w = min(dp[i-1][j-1], min(dp[i-1][j], dp[i-1][j+1]));
                dp[i][j] += w;
            }
        }
        int MN = 1<<30;;
        for(int i=1; i<=n; i++)
            MN = min(dp[m][i], MN);
        printf("%d\n", MN);
    }

    return 0;
}
