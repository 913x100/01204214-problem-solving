#include <iostream>
#include <string>

using namespace std;

int main()
{
    char opt;
    int n, sum, x;
    cin >> n;
    cin >> sum;
    n--;
    while(n--) {
        cin >> opt;
        cin >> x;
        if(opt == '+') sum += x;
        if(opt == '-') sum -= x;
    }
    cout << sum << endl;
    return 0;
}
