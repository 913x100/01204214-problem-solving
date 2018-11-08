#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> x;

///long long x[100100];

int main()
{
    long long res = 0;
    int n, A, B, p1, p2,pp;
    scanf("%d %d %d", &n, &A, &B);
    printf("%d\n", B);
    for(int i=0; i<n; i++)
    {
        scanf("%lld", &pp);
        x.push_back(pp);
    }
    //scanf("%lld", &x[i]);
    //sort(x.begin(), x.end());

    for(int i=0; i<n; i++)
        printf("%d ", x[i]);
    printf("\n%d\n", B);
    for(int i=0; i<n; i++)
    {
        printf("%d-%d = %d\n", B, x[i], B-x[i]);
        //p1 = lower_bound(x.begin()+i, x.end(), A-x[i])-x.begin();

        //p2 = lower_bound(x.begin()+i, x.end(), B-x[i])-x.begin();


        //if(x[p2] != b-x[i])
        //    p2--;
        printf("p1:%d p2:%d\n", p1, p2);
        res += p2-p1+1;
        printf("%d\n", p2-p1+1);
    }
    printf("%lld\n", res);
    return 0;
}
