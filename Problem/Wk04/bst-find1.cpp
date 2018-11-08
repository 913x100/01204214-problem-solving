#include <cstdio>

using namespace std;

struct node
{
    int val;
    node *l, *r;

    node(int val, node *l=0, node *r=0)
        : val(val), l(l), r(r) {}
};

void insert_bst(node* &root, int key)
{
    if(root == 0) {
        root = new node(key);
        return ;
    }

    node *cur = root;
    while(1)
    {
        if(key < cur->val) {
            if(cur->l != 0)
                cur = cur->l;
            else {
                cur->l = new node(key);
                break;
            }
        }
        else {
            if(cur->r != 0)
                cur = cur->r;
            else {
                cur->r = new node(key);
                break;
            }
        }
    }
}

int find_bst(node* root ,int key)
{
    node *cur = root;
    while(cur != 0) {
        if(cur->val == key)
            return 1;
        if(key < cur->val)
            cur = cur->l;
        else
            cur = cur->r;
    }
    return 0;
}

int main()
{
    node *root = 0;
    int m, k, x;
    scanf("%d", &m);
    while(m--)
    {
        scanf("%d %d", &k, &x);
        if(k == 1)
        {
            insert_bst(root, x);
            //printf("%d \n", bst->val);
        }
        else if(k == 2)
        {
            printf("%d\n", find_bst(root, x));
        }
    }
    return 0;
}
