#include <iostream>

using namespace std;

string cmd;

int min_of_three(int a, int b, int c)
{
    if(a <= b && a <= c) return a;
    if(b <= a && b <= c) return b;
    return c;
}

int main()
{
    int n, x;
    int item1_price, item2_price, item3_price;
    int item1_cnt=0, item2_cnt=0, item3_cnt=0;
    cin >> item1_price >> item2_price >> item3_price;
    cin >> n;
    while(n--) 
    {
        cin >> x;
        if(x == 1) item1_cnt++;
        else if(x == 2) item2_cnt++;
        else if(x == 3) item3_cnt++;
    }

    cout << min_of_three(item1_cnt*item1_price, item2_cnt*item2_price, item3_cnt*item3_price) << endl;

    return 0;
}
