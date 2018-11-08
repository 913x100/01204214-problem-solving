#include <cstdio>
#include <set>

using namespace std;

set<int> myset;

int main()
{
    int m, n, cmd;
    scanf("%d", &m);
    while(m--) {
        scanf("%d %d", &cmd, &n);
        if(cmd == 1)
            myset.insert(n);
        else if(cmd == 2)
            printf("%d\n", myset.find(n)!=myset.end());
        else if(cmd == 3)
            myset.erase(n);
    }
    return 0;
}
