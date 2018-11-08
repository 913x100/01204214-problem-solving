#include <cstdio>
#include <map>

using namespace std;

map<int, int> m;

int main()
{
    int k, n, mx=0, id_mx;
    scanf("%d", &k);
    for(int i=0; i<k; i++) {
        scanf("%d", &n);
        m[n]++;
        if(m[n] >= mx) {
            mx = m[n];
            id_mx = n;
        }
        printf("%d\n", id_mx);
    }
    return 0;
}
