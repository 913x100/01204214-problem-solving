#include <stdio.h>

struct comp{
    int id, p;

    bool operator>(const comp a)const
    {
        return p > a.p;
    }
};

comp player[5];
comp wA, wB, lA, lB;

void competition(int round, int n)
{
    int x, index=0, MX=0;
    for(int i=1; i<=n; i++) {
        scanf("%d", &x);
        if(x > MX) MX =x, index = i;
    }
    player[round+1] = {round*n+index, MX};
}

int main()
{
    int idx[5], a[5];
    int n;
    scanf("%d", &n);
    competition(0, n);
    competition(1, n);
    competition(2, n);
    competition(3, n);

    if(player[1] > player[2])
        wA = player[1], lA = player[2];
    else
        wA = player[2], lA = player[1];

    if(player[3] > player[4])
        wB = player[3], lB = player[4];
    else
        wB = player[4], lB = player[3];

    if(wA > wB)
        printf("%d %d ", wA.id, wB.id);
    else
        printf("%d %d ", wB.id, wA.id);
    printf("%d %d\n", lA.id, lB.id);

    return 0;
}
