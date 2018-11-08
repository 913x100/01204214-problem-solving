#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int u,v, w;
} Edge;
Edge e[510500];
int parent[1100],height[1100],rootu,rootv;
double sum=0;
int find(int p)
{
    if(parent[p]!=p)
        p=find(parent[p]);
    return p;
}
int Union(int u,int v)
{
    if(height[u]>height[v])
        parent[v]=parent[u];
    else if(height[u]<height[v])
        parent[u]=parent[v];
    else
    {
        parent[v]=parent[u];
        height[u]++;
    }
}
int cmp (const void *a,const void *b)
{
    if(((Edge *)a)->w > ((Edge *)b)->w) return 1;
    return -1;
}
int main()
{
    int n,ne,i,tmp;
    scanf("%d %d",&n,&ne);
    for(i=0; i<ne; i++)
    {
        scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
    }
    qsort(e,ne,sizeof(Edge),cmp);
    for(i=0;i<n;i++)
        height[i]=0,parent[i]=i;
    for(i=0;i<ne;i++)
    {
        rootu=find(e[i].u);
        rootv=find(e[i].v);
        if(rootu!=rootv)
        {
            sum+=e[i].w;
            Union(rootu,rootv);
        }
    }
    printf("%d\n",sum);
    return 0;
}
