#include <cstdio>
#include <cstring>

char c[1010];

long long pow(long long a,long long n)
{
    long long p;
    if(n==0)    return 1;
    p=pow(a,n/2);
    if(n%2) return p*p*a;
    else return p*p;
}

int main()
{
    bool flag = false;
    int cnt = 0;
    scanf("%s", c);
    int len = strlen(c);
    for(int i=0; i<len-1; i++)
    {
        if(!flag && c[i] >= '0' && c[i] <= '9') {
            cnt++;
            flag = true;
        }
        if(c[i] == ',')
            flag = false;
    }
    printf("%lld\n", pow(2, cnt));
    return 0;
}
