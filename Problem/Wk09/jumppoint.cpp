#include <cstdio>
#include <queue>

using namespace std;

struct node{
    int x, y, cnt;
};

bool mark[1010];
int n ,r;
node v[1010];
queue<node> q;

int dist(int x1, int y1, int x2, int y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

void BFS()
{
    int x, y, cnt;
    q.push(node{0, 0, 0});

    while(!q.empty()) {
        x = q.front().x;
        y = q.front().y;
        cnt = q.front().cnt;
        q.pop();

        //printf("%d %d\n", x, y);

        if(x == 100 && y == 100) {
            printf("%d\n", cnt);
            return ;
        }

        for(int i=0; i<=n; i++) {
            if(!mark[i] && dist(x, y, v[i].x, v[i].y) <= r*r) {
                mark[i] = true;
                q.push(node{v[i].x, v[i].y, cnt+1});
            }
        }
    }
    printf("-1");
}

int main()
{
    scanf("%d %d", &n, &r);
    for(int i=0; i<n; i++)
        scanf("%d %d", &v[i].x, &v[i].y);
    v[n] = node{100, 100, 0};
    BFS();

    return 0;
}
