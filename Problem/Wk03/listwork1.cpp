#include <cstdio>

struct node{
    int val;
    node *next;

    node(int val, node *next=0)
        : val(val), next(next){}
};

node *head = NULL;
int listSize = 0;

/*node* addNode(int n)
{
    node *newNode = new node;
    newNode->num = n;
    newNode->next = NULL;

    return newNode;
}*/

void insertNode(int n)
{
    node *newNode = new node(n);

    newNode->next = head->next;
    head->next = newNode;
    listSize++;
}

void deleteNode(int n)
{
    if(n > listSize) return ;

    node *cur = head;
    node *prev = head;
    for(int i=0; i<n; i++) {
        prev = cur;
        cur = cur->next;
    }
    prev->next = cur->next;
    cur->next = NULL;
    delete cur;
    listSize--;
}

void printNode()
{
    node *cur = head->next;
    while(cur != NULL) {
        printf("%d\n", cur->val);
        cur = cur->next;
    }
}

int main()
{
    char cmd;
    int m, n;
    head = new node(0);
    scanf("%d", &m);
    while(m--) {
        scanf(" %c %d", &cmd, &n);

        if(cmd == 'I') {
            insertNode(n);
            //printNode();
        } else if(cmd == 'D') {
            deleteNode(n);
            //printNode();
        }
    }
    printNode();
    return 0;
}
