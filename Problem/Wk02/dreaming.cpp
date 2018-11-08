#include <cstdio>
#include <cstring>
using namespace std;

char str[400];
int a[400], b[400], res[400];
int main()
{
    int lenA, lenB, len;

    scanf("%s", str);
    lenA = strlen(str);
    for(int i=lenA-1; i>=0; i--)
        a[lenA-i-1] = str[i] - '0';

    scanf("%s", str);
    lenB = strlen(str);
    for(int i=lenB-1; i>=0; i--)
        b[lenB-i-1] = str[i] - '0';

    if(lenA > lenB) len = lenA;
    else len = lenB;

    for(int i=0; i<len; i++)
    {

        if(res[i] + a[i] + b[i] > 9)
            res[i+1]++;
        res[i] = (res[i]+a[i]+b[i])%10;
    }
    if(res[len])
        printf("%d", res[len]);
    for(int i=len-1; i>=0; i--)
        printf("%d", res[i]);
    return 0;
}


