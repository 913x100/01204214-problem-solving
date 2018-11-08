#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[1010], a[1010];

struct node{
    int val;
    int cnt;

    bool operator<(const node &a)const
    {
        if(val == a.val)
            return cnt < a.cnt;
        return val < a.val;
    }
};
node b[1010];

int main()
{
    int n, k, x, tmp;
    memset(a, 0xff, sizeof(a));
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &x);
        dp[i] = dp[i-1] + x;
        for(int j=0; j<i; j++)
        {
            tmp = dp[i]-dp[j];
            if(a[i-j] == -1)
                a[i-j] = tmp;
            else
                a[i-j] = (a[i-j] < tmp)?a[i-j]:tmp;
        }
    }
    for(int i=1; i<=n; i++)
    {
        b[i].val = a[i];
        b[i].cnt = i;
    }
    sort(b, b+n+1);
    /*for(int i=1; i<=n; i++) {
        //printf("%d %d\n", b[i].cnt, b[i].val);
    }*/


    while(k--) {
        scanf("%d", &x);
        int p = lower_bound(a, a+n, x)-a;
        //printf("%d\n", b[p].cnt);
        printf("%d\n", (b[p].val==x)?b[p].cnt:b[p].cnt-1);

    }
    return 0;
}
