#include <cstdio>
#include <map>
#include <string>
#include <iostream>

using namespace std;

map<int, int> m;
int main()
{
    int k, cmd, a, b, tmp;
    scanf("%d", &k);
    while(k--)
    {
        scanf("%d", &cmd);
        if(cmd == 1)
        {
            scanf("%d %d", &a, &b);
            m[a]+=b;
        }
        else if(cmd == 2)
        {
            scanf("%d", &a);
            printf("%d\n", m[a]);
        }
        else if(cmd == 3)
        {
            scanf("%d %d", &a, &b);
            tmp = m[a]-b;
            if(tmp >= 0) {
                printf("%d\n", b);
                m[a]-=b;
            } else {
                printf("%d\n", tmp+b);
                m[a]=0;
            }
        }
    }
    return 0;
}
