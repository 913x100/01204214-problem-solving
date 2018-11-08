#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int N, x, sum=0, res=0;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> x;
        if(sum+x > 1000)
            res++, sum=x;
        else
            sum += x;
    }
    cout << res+1 << endl;
    return 0;
}
