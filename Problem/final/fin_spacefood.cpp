#include <cstdio>

int main()
{
    int n, m, k, food, sum=0, res=0;
    scanf("%d %d %d", &n, &m, &k);
    while(n--) {
        scanf("%d", &food);
        sum = sum+food;
        if(sum < m) {
            printf("-1");
            return 0;
        }
        if(sum < k) {
            res++;
            sum = 0;
        }
        else
            sum -= k;
    }
    printf("%d\n", res);
    return 0;
}
