#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX(a, b) (a>=b)?a:b

using namespace std;

struct job{
    int s, e, w;

    bool operator<(const job &a)const {
        return e < a.e;
    }
};
job a[1010];

int dp[1010], p[1010];
vector<int> res;

int findLastest(int index)
{
    for(int i=index-1; i>=0; i--) {
        if(a[index].s >= a[i].e)
            return i;
    }
    return 0;
}

int main()
{
    int n, price;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d %d %d", &a[i].s, &a[i].e, &a[i].w);

    a[0].s = a[0].e = a[0].w = 0;
    sort(a+1, a+n+1);
    dp[0] = p[0] = 0;
    for(int i=1; i<=n; i++) {
        price = a[i].w;
        p[i] = findLastest(i);
        dp[i] = MAX(dp[p[i]] + price, dp[i-1]);
    }

    int i = n;
    while(i) {
        if(a[i].w + dp[p[i]] >= dp[i-1]) {
            res.push_back(i);
            i = p[i];
        } else
            i--;
    }
    printf("%d\n%d\n", dp[n], res.size());
    for(int i=res.size()-1; i>=0; i--)
        printf("%d ", res[i]);
    return 0;
}
