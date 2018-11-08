#include <cstdio>

using namespace std;

struct node
{
    int val, numRight;
    node *l, *r;

    node(int val, int numRight=0, node *l=0, node *r=0)
        : val(val), numRight(numRight), l(l), r(r) {}
};

int res = 0;

node* insert_bst(node* cur, int key)
{

    if(cur == 0) return new node(key);

    //printf("%d ", cur->val);

    if(key < cur->val)
        cur->l = insert_bst(cur->l, key);
    else {
        cur->numRight++;
        cur->r = insert_bst(cur->r, key);
    }
    return cur;

}

int search_bst(node* cur, int key)
{
    if(cur == 0) return -1;
    if(cur->val == key) return cur->numRight;

    if(key < cur->val)
        search_bst(cur->l, key);
    else
        search_bst(cur->r, key);

    return -1;
}

void count_more(node* cur, int key)
{
    if(cur == 0) return ;
    if(key < cur->val) {
        //printf("%d %d\n", cur->val, cur->numRight);
        res += cur->numRight + 1;
        count_more(cur->l, key);
    }
    else  {
        //res += 1;
        count_more(cur->r, key);
    }

}

int main()
{
    node *root = 0;
    int n, x, k;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %d", &k, &x);
        if(k == 1) {
            if(root == 0)
                root = insert_bst(root, x);
            else
                insert_bst(root, x);
        } else if(k == 2) {
            res = 0;
            //if(root != 0 && x <= root->val)
            //   res = 1;
            count_more(root, x);
            printf("%d\n", res);
        } else if(k == 3) {
            printf("%d\n", search_bst(root, x));
        }
    }
    //inorder(root);
    return 0;
}
