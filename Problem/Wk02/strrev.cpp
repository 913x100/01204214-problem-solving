#include <cstdio>
#include <cstring>
using namespace std;

char str[1005];
int main()
{
    int len;
    scanf("%s", str);
    len = strlen(str);
    for(int i=len-1; i>=0; i--)
        printf("%c", str[i]);

    return 0;
}


