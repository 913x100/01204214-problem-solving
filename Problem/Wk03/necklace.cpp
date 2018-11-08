#include <cstdio>
#include <cstring>

struct node{
    int val;
    node *l;
    node *r;

    node(int val, node *l=0, node *r=0)
        : val(val), l(l), r(r){}
};


int root[300100];
node *head[300100];
node *tail[300100];

void insert_list(int x, int y)
{
    tail[x]->r = head[y]->r;
    head[y]->r->l = tail[x];
    head[y]->r = head[x];
    head[x]->l = head[y];
}

void printNode(int n)
{
    node *cur = head[n];
    //printf("%d %d\n", cur->val, tail[n]->val);
    while(cur->val != tail[n]->val) {
        if(cur->val > 0)
            printf("%d ", cur->val);
        cur = cur->r;
    }
    printf("\n");
}

int main()
{
    int n, x, y;
    scanf("%d", &n);
    for(int i=0; i<=n; i++) {
        head[i]= new node(i);
        tail[i] = new node(-i);
        head[i]->r = tail[i];
        tail[i]->l = head[i];

        root[i] = i;
    }
    for(int i=1; i<n; i++) {
        scanf("%d %d", &x, &y);
        insert_list(x, y);
        //printNode(y);
        root[x] = y;
    }

    int node = 1;
    for(int i=1; i<=n; i++) {
        if(root[i] == i)
            node = i;
    }
    //printf("%d\n", node);
    printNode(node);
    return 0;
}
