#include <cstdio>

#define MAX(a, b) (a>b)?a:b

int dp[100100], a[100100];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", &a[i]);
    for(int i=3; i<=n; i++) {
        dp[i] = MAX(dp[i-3]+a[i], dp[i-1]);
    }
    printf("%d\n", dp[n]);
    return 0;
}
