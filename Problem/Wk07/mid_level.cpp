#include <cstdio>

int level[105][3];
bool pass[3];
int main()
{
    int n, m, stage=1, a, b, c;
    scanf("%d %d", &n, &m);
    for(int i=1; i<n; i++)
        scanf("%d %d %d", &level[i][0], &level[i][1], &level[i][2]);
    while(m--)
    {
        scanf("%d %d %d", &a, &b, &c);
        if(a >= level[stage][0]) pass[0] = true;
        if(b >= level[stage][1]) pass[1] = true;
        if(c >= level[stage][2]) pass[2] = true;

        if(pass[0] && pass[1] && pass[2]) {
            stage = (stage+1 > n)?n:stage+1;
            pass[0]=pass[1]=pass[2] = false;
        }
    }
    printf("%d\n", stage);
    return 0;
}
