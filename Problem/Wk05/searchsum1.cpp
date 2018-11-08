#include <cstdio>
#include <algorithm>

using namespace std;

int dp[100100];

int main()
{
    int n, k, x;
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &x);
        dp[i] = dp[i-1] + x;
    }
    dp[n+1] = dp[n]+1;
    while(k--) {
        scanf("%d", &x);
        int p = lower_bound(dp, dp+n+1, x)-dp;
        printf("%d\n", (dp[p]==x)?p:p-1);

    }
    return 0;
}
