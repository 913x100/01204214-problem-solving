#include <cstdio>
#include <algorithm>

using namespace std;

struct node{
    int i, p, n;

    bool operator<(const node a)const
    {
        return i<a.i;
    }
};

node store[100100];
int main()
{
    int n, q, x, res = 0, MN = 1<<29, index;
    scanf("%d %d", &n, &q);
    for(int i=0; i<n; i++)
        scanf("%d %d %d", &store[i].i, &store[i].p, &store[i].n);
    sort(store, store+n);

    while(q--) {
        MN = 1<<29;
        index = -1;
        scanf("%d", &x);
        int p1 = lower_bound(store, store+n, node{x-5, 0, 0})-store;
        int p2 = upper_bound(store, store+n, node{x+5, 0, 0})-store -1;

        for(int i=p1; i<=p2; i++) {
            if(store[i].n > 0 && store[i].p < MN)
                MN = store[i].p, index = i;
        }
        if(index == -1)
            MN = 0;
        else
            store[index].n--;
        printf("%d\n", MN);
    }
    return 0;
}
