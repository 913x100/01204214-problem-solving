#include <iostream>
#include <cstdlib>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main()
{
    int N, M;
    cin >> N >> M;
    int x = gcd(N, M);
    cout << N/x << "/" << M/x << endl;

    return 0;

}
