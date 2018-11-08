#include <cstdio>

using namespace std;

char str[105];
int main()
{
    scanf("%s", str);
    for(int i=0; str[i]!='\0'; i++)
    {
        str[i] = (str[i]-'a'+4)%26 + 'a';
    }
    printf("%s", str);

    return 0;
}

