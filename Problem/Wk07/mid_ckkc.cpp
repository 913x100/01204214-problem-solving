#include <cstdio>

bool mark[1010];
bool ck = false;
int main()
{
    int x, year;
    scanf("%d", &x);
    while(1) {
        scanf("%d", &year);
        if(year == 0) break;
        mark[year-2558] = true;
    }
    for(int i=1; i<=x-2558; i++){
        if(!mark[i])
            ck = !ck;
    }
    printf("%c", ck?'C':'K');
    return 0;
}

