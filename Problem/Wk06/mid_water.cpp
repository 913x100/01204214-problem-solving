#include <cstdio>

int main()
{
    int n, now, prev, res=0;
    scanf("%d", &n);
    n--;
    scanf("%d", &prev);
    while(n--) {
        scanf("%d", &now);
        if(prev-now > 10)
            res += (prev-now > 70)? 700:(prev-now)*10;
        prev = now;
    }
    printf("%d\n", res);
    return 0;
}
