#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> ans[100010];
int a[100010], b[100010], c[100010];

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
        ans[p].push_back(a[i]);
    }
    printf("%d\n", len+1);
    n = 1<<30;
    for(int i=len; i>=0; i--) {
        int j;
        for(j=0; j<ans[i].size(); j++) {
            if(ans[i][j] < n)
                break;
        }
        n = ans[i][j];
        c[tmp++] = n;
    }

    for(int i = tmp-1; i>=0; i--)
        printf("%d ", c[i]);
    return 0;
}
