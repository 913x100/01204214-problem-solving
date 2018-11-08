#include <cstdio>
#include <queue>

using namespace std;

priority_queue<int> q;

int main()
{
    double x,y,w;
    int t,l,h,n,m;
    scanf("%d %d %d",&t,&l,&h);
    while(t--)
    {
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&m);
            q.push(m);
        }
        scanf("%lf %lf",&x,&y);

        w=(h*x)/y;

        w+=l;
        while(!q.empty() && q.top() >= w)
            q.pop();
        printf("%d\n",q.size());

    }
    return 0;
}

