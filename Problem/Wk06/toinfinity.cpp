#include<cstdio>
#include<cstdlib>

int main()
{
    int n,r,x,y,i,mn=1<<30;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d %d",&x, &y, &r);
        y=abs(y)-r;
        if(y<mn)  mn=y;
    }
    if(mn<=0) printf("-1\n");
    else        printf("%d\n", mn);

}

