#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
queue <PII> q;

int h,w,mark[35][35];
char a[35][35];
int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void BFS()
{
    int i,j,k,newi,newj;
    while(!q.empty())
    {
        i=q.front().first;
        j=q.front().second;
        q.pop();
        mark[i][j]=1;
        for(k=0;k<4;k++)
        {
            newi=i+d[k][0],newj=j+d[k][1];
            if(mark[newi][newj])    continue;

            if(a[newi][newj]=='.' && a[newi][newj+1]=='.' && a[newi+1][newj]=='.' && a[newi+1][newj+1]=='.')
            {
                if(newi+1==h)
                {
                    printf("yes\n");
                    exit(0);
                }
                q.push(PII(newi,newj));
            }
        }
    }
}
int main()
{
    int i,j,ans;
    scanf("%d %d",&h,&w);
    for(i=1;i<=h;i++)
        for(j=1;j<=w;j++)
            scanf(" %c", &a[i][j]);

    for(i=1;i<w;i++)
        if(a[1][i]=='.' && a[1][i+1]=='.' && a[2][i]=='.' && a[2][i+1]=='.')
            q.push(PII(1,i));
    BFS();
    printf("no\n");
}
