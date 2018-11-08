#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int a[100010], b[100010];

int main()
{
    int n, len = 0, tmp=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        b[i] = 1<<30;
    }
    for(int i=0; i<n; i++) {
        int p = lower_bound(b, b+len+1, a[i])-b;
        len = (p>len)?p:len;
        b[p] = a[i];
    }
    printf("%d\n", len+1);
    return 0;
}
