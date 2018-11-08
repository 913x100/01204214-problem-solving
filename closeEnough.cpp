#include <iostream>
#include <cstdlib>

using namespace std;

int a[11];

int main()
{
    int N, L, res=0;
    cin >> N >> L;
    for(int i=0; i<N; i++)
        cin >> a[i];
    for(int i=0; i<N; i++)
    {
        for(int j=i+1; j<N; j++)
        {
            if(abs(a[i] - a[j]) <= L)
                res++;
        }
    }
    cout << res << endl;

    return 0;
}
