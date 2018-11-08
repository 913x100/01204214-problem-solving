#include <cstdio>

int a[110][110], b[110][110];

int abs(int a)
{
    return (a < 0)?-a:a;
}

int main()
{
    int l, h, R;
    scanf("%d %d %d", &l, &h, &R);

    for(int i=1; i<=h; i++)
    {
        for(int j=1; j<=l; j++)
            scanf("%d", &a[i][j]);
    }
    for(int i=1; i<=h; i++)
    {

        for(int j=1; j<=l; j++)
        {
            int sum = 0, cnt=0;

            for(int ri = i-R; ri <= i+R; ri++)
            {
                for(int rj = j-R; rj <= j+R; rj++)
                {
                    //printf("x");
                    if(ri < 1 || rj < 1 | ri > h || rj > l)
                        continue;
                    //if(i+ri > h || j+rj > l || i-ri < 1 || j-rj < 1)
                    //    continue;


                    if(abs(ri-i) + abs(rj-j) <= R)
                    {
                        //printf("%d&", abs(ri-i) + abs(rj-j));
                        //printf("xx");
                        //printf("%d ", a[ri][rj]);
                        sum += a[ri][rj];
                        cnt++;
                    }
                }
            }
            //printf(":%d %d\n", sum, cnt);
            b[i][j] = sum / cnt;

        }
        //printf("-----------------------\n");
    }

    for(int i=1; i<=h; i++)
    {
        for(int j=1; j<=l; j++)
            printf("%d ", b[i][j]);
        printf("\n");
    }
    return 0;
}
