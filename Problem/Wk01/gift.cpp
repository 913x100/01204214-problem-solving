#include <iostream>

using namespace std;

int main()
{
    int n, x, sum=0;
    cin >> n;
    while(n--)
    {
        cin >> x;
        if(x > 0) sum+=x;
    }
    cout << sum << endl;

    return 0;
}
