#include <cstdio>

int main()
{
    int n, a, b, r, x, y, res=0;
    scanf("%d %d %d %d", &n, &a, &b, &r);
    while(n--) {
        scanf("%d %d", &x, &y);

        if((a-x)*(a-x) + (b-y)*(b-y) <= r*r)
            res++;
    }
    printf("%d\n", res);
    return 0;
}
