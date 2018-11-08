#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

//vector<long long> x;

long long x[200100];

int main()
{
    long long a, b;
    long long res = 0;
    int n, p1, p2,pp;
    scanf("%d %lld %lld", &n, &a, &b);
    for(int i=0; i<n; i++)
    {
        //printf("\n%d\n", B);
        scanf("%lld", &x[i]);
        //x.push_back(pp);
    }
    //printf("\n%d\n", B);
    //scanf("%lld", &x[i]);
    sort(x, x+n);
    //printf("\n%d\n", B);
    for(int i=0; i<n; i++)
    {
        //printf("%lld-%lld = %lld\n", b, x[i], b-x[i]);
        p1 = lower_bound(x+i, x+n, a-x[i])-x;

        p2 = upper_bound(x+i, x+n, b-x[i])-x;

        if(p1 <= n && x[p1] == x[i])
            p1++;

        if(p2 >=0 && x[p2] != b-x[i])
            p2--;
        //printf("p1:%d p2:%d\n", p1, p2);
        if(p2 >= p1)
            res += p2-p1+1;
        //printf("%d\n", p2-p1+1);
    }
    printf("%lld\n", res);
    return 0;
}
