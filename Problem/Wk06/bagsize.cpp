#include <cstdio>

int w[1010];

int main()
{
    int n, a, b, mx = 0, sum = 0, diff, mn = 1<<30, res;
    scanf("%d %d %d", &n, &a, &b);
    for(int i=0; i<n; i++) {
        scanf("%d", &w[i]);
        if(w[i] > mx) mx = w[i];
    }
    for(int i=mx; i<=b; i++) {
        sum = 0;
        diff = 0;
        for(int j=0; j<n; j++) {
            if(sum + w[j] > i) {
                diff += (i - sum);
                sum = w[j];
            } else {
                sum += w[j];
            }
        }
        diff += i-sum;
        if(diff < mn) mn = diff, res = i;
    }
    printf("%d\n", res);
    return 0;
}
