#include <cstdio>
#include <queue>

using namespace std;

struct node{
    int i, j, w;

    bool operator<(const node &a)const
    {
        return w > a.w;
    }
};

int a[35][35];
bool isRelax[35][35];
int dist[35][35];

priority_queue<node> q;

int main()
{
    int H, W;
    scanf("%d %d", &H, &W);
    for(int i=1; i<=H; i++)
        for(int j=1; j<=W; j++)
        {
            scanf(" %c", &a[i][j]);
            isRelax[i][j] = false;
        }


    q.push(node{H, 1, 0});
    isRelax[H][1] = true;

    while(!q.empty())
    {
        int i = q.top().i;
        int j = q.top().j;
        int w = q.top().w;
        isRelax[i][j] = true;
        q.pop();
        //printf("%d %d %d\n", i, j, w);
        if(i-1 > 0 && a[i-1][j] != 'X' && !isRelax[i-1][j])
        {
            isRelax[i-1][j] = true;
            dist[i-1][j] = w + 5;
            q.push(node{i-1, j, w+5});
        }
        if(i+1 <= H && a[i+1][j] != 'X' && !isRelax[i+1][j])
        {
            isRelax[i+1][j] = true;
            dist[i+1][j] = w;
            q.push(node{i+1, j, w});
        }
        if(j-1 > 0 && a[i][j-1] != 'X' && !isRelax[i][j-1])
        {
            isRelax[i][j-1] = true;
            dist[i][j-1] = w + 1;
            q.push(node{i, j-1, w+1});
        }
        if(j+1 <= W && a[i][j+1] != 'X' && !isRelax[i][j+1])
        {
            isRelax[i][j+1] = true;
            dist[i][j+1] = w + 1;
            q.push(node{i, j+1, w+1});
        }
    }

    /*for(int i=1; i<=H; i++)
    {
        for(int j=1; j<=W; j++)
            printf("%d ", dist[i][j]);
        printf("\n");
    }*/
    if(!isRelax[1][W])
        printf("-1\n");
    else
        printf("%d\n", dist[1][W]);
    return 0;
}
