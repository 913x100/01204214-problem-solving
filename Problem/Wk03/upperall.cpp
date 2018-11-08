#include <cstdio>

using namespace std;

char str[105];
int main()
{
    scanf("%s", str);
    for(int i=0; str[i]!='\0'; i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i]-'a'+'A';
    }
    printf("%s", str);

    return 0;
}

