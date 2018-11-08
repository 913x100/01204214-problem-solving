#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

struct node{
    int e, w, ex;

    bool operator<(const node a)const
    {
        return w > a.w;
    }
};
vector<node> v[1010];
priority_queue<node> q;

int dist[1010][2];
bool isRelax[1010][2];

int main()
{
    int n, m, s, e, w, ex, u, k;
    scanf("%d %d", &n, &m);
    while(m--)
    {
        scanf("%d %d %d %d", &s, &e, &w, &ex);
        v[s].push_back(node{e,w,ex});
        v[e].push_back(node{s,w,ex});
    }
    q.push(node{1, 0, 0});
    isRelax[1][0] = true;

    while(!q.empty())
    {
        e = q.top().e;
        w = q.top().w;
        k = q.top().ex;
        q.pop();

        for(int i=0; i<v[e].size(); i++)
        {
            u = v[e][i].e;
            ex = v[e][i].ex;

            if(!isRelax[u][k]) {
                if(k == 0 && ex == 1)
                {
                    q.push(node{u, w+v[e][i].w, 1});
                    dist[u][1] = w+v[e][i].w;
                    isRelax[u][1] = true;
                }
                else if(!(k == 1 && ex == 1))
                {
                    q.push(node{u, w+v[e][i].w, k});
                    dist[u][k] = w+v[e][i].w;
                    isRelax[u][k] = true;
                }
            }
        }
    }
    if(!isRelax[n][1])
        printf("-1\n");
    else
        printf("%d\n", dist[n][1]);


    return 0;
}
