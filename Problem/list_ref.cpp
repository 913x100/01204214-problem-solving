#include <cstdio>

using namespace std;

struct node {
    int val;
    node* next;
    node(int val, node *next = 0) : val(val), next(next) {}
};

int main()
{
    node *List[100], *head[100];

    head[0] = new node(11);
    tail[0] = head[0];
    tail[0]->next = new node(12);
    tail[0]->next = new node(13);
    tail[0] = tail[0]->next;
    //printf("%d %d",head[0]->val, tail[0]->val);
    head[1] = new node(21);
    tail[1] = head[1];
    tail[1]->next = new node(22);
    tail[1]->next = new node(23);
    tail[1] = tail[1]->next;

    head[2] = new node(31);
    tail[2] = head[2];
    tail[2]->next = new node(32);
    tail[2]->next = new node(33);
    tail[2] = tail[2]->next;

    tail[0] = tail[1];
    printf("tail[0] %d\n", tail[0]->val);

    printf("tail[1] %d\n", tail[1]->val);
    tail[1] = tail[2];
    printf("tail[1] %d\n", tail[1]->val);
    printf("tail[0] %d\n", tail[0]->val);



    return 0;
}
