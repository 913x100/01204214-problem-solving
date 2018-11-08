#include <cstdio>
#include <map>

using namespace std;

map<int, int> mymap;

int main()
{
    int n, m,x;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        mymap[x]=0;
    }
    while(m--) {
        scanf("%d", &x);
        map<int, int>::iterator it = mymap.lower_bound(x);

        int p = it->first;
        int status = it->second;

        if(p == x || abs((it-1)->first - x))
    }
    return 0;
}
