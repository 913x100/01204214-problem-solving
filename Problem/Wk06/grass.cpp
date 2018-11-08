#include <cstdio>

char a[110][110];
int n;

void eat_plus(int k, int type)
{
    int row, col;
    if(type == 1)
        row = k;
    else
        col = k;
    for(int i=1; i<=n; i++) {
        if(type == 1)
            col = i;
        else
            row = i;
        if(a[row][col] == '.' || a[row][col] == '#')
            return ;
        else
            a[row][col] = '.';
    }
}

void eat_minus(int k, int type)
{
    int row, col;
    if(type == 1)
        row = k;
    else
        col = k;
    for(int i=n; i>0; i--) {
        if(type == 1)
            col = i;
        else
            row = i;
        if(a[row][col] == '.' || a[row][col] == '#')
            return ;
        else
            a[row][col] = '.';
    }
}

void plant(int k, int type)
{
    int row, col;
    if(type == 1)
        row = k;
    else
        col = k;
    for(int i=1; i<=n; i++) {
        if(type == 1)
            col = i;
        else
            row = i;
        if(a[row][col] != '#')
            a[row][col] = 'x';
    }
}

int main()
{
    char cmd;
    int m, k;
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf(" %c", &a[i][j]);
    /*for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            printf("%c", a[i][j]);
        printf("\n");
    }*/


    while(m--) {
        scanf(" %c %d", &cmd, &k);
        if(cmd == 'L')
            eat_plus(k, 1);
        else if(cmd == 'R')
            eat_minus(k, 1);
        else if(cmd == 'U')
            eat_plus(k, 2);
        else if(cmd == 'D')
            eat_minus(k, 2);
        else if(cmd == 'A')
            plant(k, 1);
        else if(cmd == 'B')
            plant(k, 2);
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            printf("%c", a[i][j]);
        printf("\n");
    }
    return 0;
}
