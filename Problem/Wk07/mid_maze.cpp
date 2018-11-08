#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

struct node{
    int i, j, key;
};

char a[25][25], b[25][25];
queue<node> q;

void bfs(int si, int sj, int ei, int ej, int n)
{
    int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            b[i][j] = a[i][j];
    while(!q.empty())
        q.pop();

    q.push(node{si, sj, 1});

    while(!q.empty())
    {
        int i = q.front().i;
        int j = q.front().j;
        int key = q.front().key;
        q.pop();
        for(int k=0; k<4; k++) {
            int newi = i+d[k][0];
            int newj = j+d[k][1];

            if(newi < 1 || newj < 1 || newi > n || newj > n) continue;
            if(b[newi][newj] == '#') continue;
            if(b[newi][newj] == 'O' && key == 0) continue;

            if(b[newi][newj] == 'O' && key == 1)
                key = 0;
            if(newi == ei && newj == ej) {
                //printf("%d %d\n", newi, newj);
                printf("yes\n");
                return ;
            }
            b[newi][newj] = '#';
            q.push(node{newi, newj, key});
        }
    }
    printf("no\n");
}

int main()
{
    int n, m;
    int si, sj, ei, ej;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf(" %c", &a[i][j]);
    while(m--)
    {
        scanf("%d %d %d %d", &si, &sj, &ei, &ej);

        if(a[si][sj] == '#' || a[ei][ej] == '#') {
            printf("no\n");
            continue;
        }
        bfs(si, sj, ei, ej, n);

    }

    return 0;
}

