#include <cstdio>
#include <cstring>
using namespace std;

char str[2005], res[2005], tmp[2005];
int main()
{
    int len, j=0, cnt=0;
    scanf("%s", str);
    len = strlen(str);
    str[len] = '_';
    for(int i=0; str[i]!='\0'; i++) {
        if(str[i] == '_') {
            while(j--) {
                res[cnt++] = tmp[j];
            }
            j=0;
            res[cnt++] = '_';
        } else
            tmp[j++] = str[i];
    }
    res[len] = '\0';
    printf("%s", res);
    return 0;
}

