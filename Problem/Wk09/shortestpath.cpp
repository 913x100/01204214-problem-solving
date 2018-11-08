#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

struct node{
    int v, w;

    bool operator<(const node &a)const
    {
        return w > a.w;
    }
};

vector<node> e[100100];
priority_queue<node> q;
int dist[100100];
bool isRelax[100100];

int main()
{
    int n, m, u, v, w;
    scanf("%d %d", &n, &m);
    while(m--) {
        scanf("%d %d %d", &u, &v, &w);
        e[u].push_back(node{v, w});
        e[v].push_back(node{u, w});
    }

    q.push(node{1, 0});

    while(!q.empty()) {
        u = q.top().v;
        w = q.top().w;
        q.pop();

        if(!isRelax[u]) {
            dist[u] = w;
            isRelax[u] = true;

            for(int i=0; i<e[u].size(); i++) {
                v = e[u][i].v;
                if(!isRelax[v])
                q.push(node{v, w+e[u][i].w});
            }
        }
    }
    printf("%d\n", dist[n]);
    return 0;
}
