#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
    if(n == 2) return true;

    if(n <= 1 || n%2 == 0) return false;

    for(int i=3; i<= sqrt(n); i+=2)
    {
        if(n%i == 0) return false;
    }
    return true;
}

int next_prime(int n)
{
    int i=n+1;
    for(; !isPrime(i); i++);

    return i;
}

int main()
{
    int n;
    cin >> n;
    cout << next_prime(n) << endl;
    return 0;
}
