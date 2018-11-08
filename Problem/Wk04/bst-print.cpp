#include <cstdio>

using namespace std;

struct node
{
    int val, level;
    node *l, *r;

    node(int val, int level, node *l=0, node *r=0)
        : val(val), level(level), l(l), r(r) {}
};

node* insert_bst(node* cur, int key, int level)
{

    if(cur == 0) return new node(key, level);

    //printf("%d ", cur->val);

    if(key < cur->val)
        cur->l = insert_bst(cur->l, key, level+1);
    else
        cur->r = insert_bst(cur->r, key, level+1);

    return cur;

}

void inorder(node *root)
{
    node *cur = root;
    if(cur == 0) return ;

    inorder(cur->r);
    for(int i=0; i<cur->level; i++)
        printf("...");
    printf("* %d \n", cur->val);
    inorder(cur->l);

}

int main()
{
    node *root = 0;
    int n, x;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &x);
        if(root == 0)
            root = insert_bst(root, x, 0);
        else
            insert_bst(root, x, 0);
    }
    inorder(root);
    return 0;
}
