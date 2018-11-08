#include <cstdio>

int dp[2][2], num[100100], p[100100];

int max(int a, int b)
{
    return (a>b)?a:b;
}

int main()
{
    int n, m, t;
    scanf("%d %d", &n, &m);

    int flag = 0;
    for(int i=1; i<=m; i++)
    {
        scanf("%d", &t);
        if(p[t] != 0 && i - p[t] < 7)
        {
            num[t]++;
            p[t] = i;
            if(num[t] >= dp[!flag][1])
            {

                if(num[t] == dp[!flag][1])
                {
                    if(t < dp[!flag][0])
                        dp[flag][0] = t;
                    else
                        dp[flag][0] = dp[!flag][0];

                }
                else
                    dp[flag][0] = t;
                dp[flag][1] = num[t];
            }
            else
            {
                dp[flag][0] = dp[!flag][0];
                dp[flag][1] = dp[!flag][1];
            }
        }
        else
        {
            num[t] = 1;
            p[t] = i;
            if(1 > dp[!flag][1])
            {
                dp[flag][0] = t;
                dp[flag][1] = 1;
            }
            else
            {
                dp[flag][0] = dp[!flag][0];
                dp[flag][1] = dp[!flag][1];
            }
        }
        flag = !flag;
    }
    flag = !flag;
    printf("%d %d\n", dp[flag][0], dp[flag][1]);
    return 0;
}
