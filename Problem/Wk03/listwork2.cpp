#include <cstdio>

struct node{
    int val;
    node *next;

    node(int val, node *next=0)
        : val(val), next(next){}
};

node *head = NULL;
node *tail = NULL;
int listSize = 0;

void insertNode(int n)
{
    node *newNode = new node(n);

    newNode->next = head->next;
    head->next = newNode;
    if(tail == head)
        tail = head->next;

    listSize++;
}

void appendNode(int n)
{
    node *newNode = new node(n);

    tail->next = newNode;
    tail = tail->next;
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
    if(cur == tail)
        tail = prev;
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
    scanf("%d", &m);
    head = new node(0);
    tail = head;
    while(m--) {
        scanf(" %c %d", &cmd, &n);

        if(cmd == 'I') {
            insertNode(n);
            //printNode();
        } else if(cmd == 'A') {
            appendNode(n);
            //printNode();
        } else if(cmd == 'D') {
            deleteNode(n);
            //printNode();
        }
        //printf("size: %d\n", listSize);
    }
    printNode();
    return 0;
}
