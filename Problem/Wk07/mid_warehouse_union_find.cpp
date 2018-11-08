#include <cstdio>
#include <vector>

using namespace std;

int h[100100], p[100100];

int Find(int i)
{
    while(i != p[i]) {
        p[i] = p[p[i]];
        i = p[i];
    }
    return i;
}

void Union(int a , int b)
{
    if(h[a] < h[b]) {
        p[a] = p[b];
        h[b] += h[a];
    } else {
        p[b] = p[a];
        h[a] += h[b];
    }
}

int main()
{
    int rootu, rootv;
    int n, m, q, u, v;
    scanf("%d %d %d", &n, &m, &q);
    for(int i=0; i<n; i++)
        p[i+1] = i+1, h[i+1]=1;
    while(m--) {
        scanf("%d %d", &u, &v);

        rootu = Find(u);
        rootv = Find(v);
        Union(rootu, rootv);
    }

    while(q--) {
        scanf("%d %d", &u, &v);
        rootu = Find(u);
        rootv = Find(v);
        printf("%d\n", rootu == rootv);
    }
    return 0;
}
