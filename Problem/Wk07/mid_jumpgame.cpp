#include <cstdio>
#include <queue>

using namespace std;

struct node{
    int i, j, h;
};

queue<node> q;

int a[25][25];
int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%d", &a[i][j]);

    q.push(node{1, 1, a[1][1]});
    a[1][1] = -1;
    while(!q.empty()) {
            int h = q.front().h;
            int i = q.front().i;
            int j = q.front().j;
            q.pop();
            if(i==n && j==n) {
                printf("yes\n");
                return 0;
            }
        for(int x=0; x<4; x++) {
            int newi = i + d[x][0];
            int newj = j + d[x][1];
            if(newi < 1 || newj < 1 || newi > n || newj > n) continue;
            if(a[newi][newj] == -1 || a[newi][newj] > h+k) continue;
            q.push(node{newi, newj, a[newi][newj]});
            a[newi][newj] = -1;
        }
    }

    while(!q.empty()) {
            int h = q.front().h;
            int i = q.front().i;
            int j = q.front().j;
            q.pop();
            if(i==n && j==n) {
                printf("yes\n");
                return 0;
            }

            if(i+1 <= n && a[i+1][j] != 0 && a[i+1][j] > h+k) {
                a[i+1][j] = -1;
                q.push(node{i+1, j, a[i+1][j]});
            }
            if(i-1 > 0 && a[i+1][j] != 0 && a[i+1][j] > h+k) {
                a[i+1][j] = -1;
                q.push(node{i+1, j, a[i+1][j]});
            }
            if(i+1 <= n && a[i+1][j] != 0 && a[i+1][j] > h+k) {
                a[i+1][j] = -1;
                q.push(node{i+1, j, a[i+1][j]});
            }
            if(i+1 <= n && a[i+1][j] != 0 && a[i+1][j] > h+k) {
                a[i+1][j] = -1;
                q.push(node{i+1, j, a[i+1][j]});
            }

    }

    printf("no\n");
}
