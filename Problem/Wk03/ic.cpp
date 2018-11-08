#include <cstdio>

struct node{
    int val;
    node *l;
    node *r;
    node(int val, node *l=0, node *r=0)
        : val(val), r(r), l(l){}
};

void insert_left(node* &head, node* &tail, int n)
{
    node *new_node = new node(n);
    if(head == 0) {
        head = new_node;
        tail = head;
        head->l = tail;
        head->r = tail;
        tail->l = head;
        tail->r = head;

    } else {
        tail->r = new_node;
        new_node->r = head;
        new_node->l = tail;
        head->l = new_node;
        head = head->l;
    }
}

void insert_right(node* &head, node* &tail, int n)
{
    node *new_node = new node(n);
    if(head == 0) {
        head = new_node;
        tail = head;
        head->l = tail;
        head->r = tail;
        tail->l = head;
        tail->r = head;
    } else {
        head->l = new_node;
        new_node->l = tail;
        new_node->r = head;
        tail->r = new_node;
        tail = tail->r;
    }
}

void rotate_left(node* &head, node* &tail)
{
    if(head == 0 || tail == 0) return ;

    head = head->r;
    tail = tail->r;
}

void rotate_right(node* &head, node* &tail)
{

    if(head == 0 || tail == 0) return ;
    //printf("y");
    tail = tail->l;
    head = head->l;
}


void print_list(node* head, node* tail)
{
    node *cur = head;
    if(head == 0 || tail == 0) return ;
    while(cur != tail) {
        printf("%d\n", cur->val);
        cur = cur->r;
    }
    printf("%d\n", cur->val);
}

void print_list_rev(node* tail)
{
    node *cur = tail;
    while(cur != 0) {
        printf("%d ", cur->val);
        cur = cur->l;
    }
}

int main()
{
    char str[5];
    int m, n;

    node *head = 0;
    node *tail = 0;
    scanf("%d", &m);
    while(m--)
    {
        scanf("%s", str);
        if(str[0]=='l' && str[1]=='i') {
            scanf("%d", &n);
            insert_left(head, tail, n);
        } else if(str[0]=='r' && str[1]=='i') {
            scanf("%d", &n);
            insert_right(head, tail, n);
        } else if(str[0]=='l' && str[1]=='r') {
            rotate_left(head, tail);
        } else if(str[0]=='r' && str[1]=='r') {
            //printf("x");
            rotate_right(head, tail);
        }
        //printf("head:%d head->r:%d head->l:%d\n", head->val, head->r->val, head->l->val);
        //printf("tail:%d tail->r:%d tail->l:%d\n", tail->val, tail->r->val, tail->l->val);
        //print_list(head, tail);
    }
    print_list(head, tail);
    return 0;
}
