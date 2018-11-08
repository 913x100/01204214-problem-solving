#include <cstdio>

int root[1010];

int find_root(int n, int x)
{
    while(n != root[n]) {
        n = root[n];
        if(n == x)
            return x;
    }
    return 0;
}

int main()
{
    bool check;
    int n, m, a, b;
    root[1] = 1;
    scanf("%d %d", &n, &m);

    for(int i=2; i<=n; i++) {
        scanf("%d", &root[i]);
    }

    while(m--) {
        scanf("%d %d", &a, &b);
        check = false;
        int res = find_root(a, b);
        if(res) {
             printf("%d\n", res);
             check = true;
        }
        res = find_root(b, a);
        if(res) {
            printf("%d\n", res);
            check = true;
        }
        if(!check)
            printf("-1\n");


    }

    return 0;
}
