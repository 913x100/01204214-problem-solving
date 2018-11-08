#include <cstdio>
#include <queue>

using namespace std;

struct node
{
    int id,n;

    bool operator<(const node &a)const
    {
        if(n < a.n) return true;
        return false;
    }
};

priority_queue<node> q;

int mark[100100];

int main()
{
    node in;
    int n,m,num,i,cnt,id;
    scanf("%d %d",&n,&m);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&num);
        in.id=i;
        in.n=num;
        q.push(in);
        mark[i]=100100;
    }
    //printf("%d %d\n",q.top().id,q.top().n);
    for(i=1; i<=m; i++)
    {
        cnt=0;
        scanf("%d",&num);
        //printf("%d\n",q.size());
        while(!q.empty() && q.top().n > num)
        {
            id=q.top().id;
            q.pop();
            if(mark[id] >= i)
            {
                if(mark[id]>i)
                    cnt++,mark[id]=i;
                if(mark[id+1]>i)
                    cnt++,mark[id+1]=i;
                if(mark[id-1]>i)
                    cnt++,mark[id-1]=i;
            }
        }
        printf("%d\n",cnt);
    }

    return 0;
}
