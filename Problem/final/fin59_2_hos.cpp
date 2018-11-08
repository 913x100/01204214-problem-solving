#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

struct node{
    int e, w, add;
};

queue<node> q;
vector<int> v[100100], hos;
int a[100100];
int mark[100100];

int main()
{
    int s, e;
    int n, m, k, h, x;
    scanf("%d %d %d %d", &n, &m, &k, &h);
    for(int i=0; i<=n; i++)
        mark[i] = -1;
    for(int i=0; i<k; i++) {
        scanf("%d", &x);
        hos.push_back(x);
    }
    for(int i=0; i<k; i++) {
        scanf("%d", &x);
        if(x == 0) a[hos[i]] = 1;
        else a[hos[i]] = 2;
    }

    while(m--) {
        scanf("%d %d", &s, &e);
        v[s].push_back(e);
        v[e].push_back(s);
    }

    for(int i=0; i<k; i++) {
        if(a[hos[i]] == 1)
            q.push(node{hos[i], 0, 2});
        else
            q.push(node{hos[i], 0, 1});
        mark[hos[i]] = 0;
    }
    int time;

    while(!q.empty()) {
        node u = q.front();
        //printf("%d %d:", u.e, u.w);
        q.pop();
        for(int i=0; i<v[u.e].size(); i++) {
            int dest = v[u.e][i];
            //printf("%d ", dest);
            int time = u.add;
            if(u.w + time <=2*h && mark[dest] == -1 || mark[dest] > u.w + time) {
                mark[dest] = u.w + time;
                //printf("(%d %d)", dest, u.w + time);
                q.push(node{dest, u.w + time, u.add});
            }
        }
        //printf("\n");
    }
    int cnt = 0;
    for(int i=1; i<=n; i++) {
        //printf("%d\n", mark[i]);
        if(mark[i] != -1 && mark[i] <= 2*h)
            cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
/*
8 8 2 2
5 2
0 1
1 2
7 1
1 3
3 4
4 5
6 5
3 6
3 8
*/
