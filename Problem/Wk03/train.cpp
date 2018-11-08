#include <cstdio>
#include <cstring>

struct node{
    int val;
    node *next;

    node(int val, node *next=0)
        : val(val), next(next){}
};

node *head[100100];
node *tail[100100];

void insertNode(int x, int n)
{
    node *newNode = new node(x);
    tail[n]->next = newNode;
    tail[n] = tail[n]->next;
}

void changeStation(int a, int b)
{
    if(head[a]->next != 0) {
        tail[b]->next = head[a]->next;
        tail[b] = tail[a];
        head[a]->next = 0;
        tail[a] = head[a];
    }

}

void printStation(int n)
{
    node *cur = head[n]->next;
    while(cur != 0) {
        printf("%d\n", cur->val);
        cur = cur->next;
    }
}

void printNode()
{
    for(int i=1; i<=100000; i++)
    {
        if(head[i]->next != 0) {
            printStation(i);
        }
    }
}

int main()
{
    char cmd;
    int m, a, b;
    scanf("%d", &m);
    //memset(head, 0, sizeof(head));
    //memset(tail, 0, sizeof(tail));
    for(int i=0; i<100010; i++)
    {
        head[i] = new node(0);
        tail[i] = head[i];
    }
    while(m--) {
        scanf(" %c %d %d", &cmd, &a, &b);

        if(cmd == 'N') {
            insertNode(a, b);
            //printStation(b);
        } else if(cmd == 'M') {
            changeStation(a, b);
            //printStation(b);
        };
    }
    printNode();
    return 0;
}
