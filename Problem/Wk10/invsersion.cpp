#include <cstdio>

long long merge_inversion(int a[], int left, int right)
{
    int mid = (left+right)/2;
    int i = left, j = mid+1;
    int tmp[right-left+1];
    int cnt=0;
    long long inversion = 0;

    while(i <= mid && j <= right) {
        if(a[i] <= a[j])
            tmp[cnt] = a[i++];
        else {
            tmp[cnt] = a[j++];
            inversion += mid - i + 1;
        }
        cnt++;
    }

    while(i <= mid)
        tmp[cnt++] = a[i++];
    while(j <= right)
        tmp[cnt++] = a[j++];

    for(int i=left; i<=right; i++)
        a[i] = tmp[i-left];

    return inversion;
}

long long divide_inversion(int a[] ,int left, int right)
{
    if(left >= right) return 0;

    int mid = (left+right)/2;

    long long m = divide_inversion(a, left, mid);
    long long n = divide_inversion(a, mid+1, right);

    long long x = merge_inversion(a, left, right);

    return m+n+x;
}

int main()
{
    int a[100100];
    int n;
    long long res;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    res = divide_inversion(a, 0, n-1);
    printf("%lld\n", res);
    return 0;
}
/*
5
1
3
10
2
7
*/
