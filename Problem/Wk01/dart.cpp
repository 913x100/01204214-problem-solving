#include <iostream>

using namespace std;

double dist(int x, int y)
{
    return x*x + y*y;
}

int main()
{
    int n, x, y, score = 0;
    cin >> n;
    while(n--)
    {
        cin >> x >> y;
        int r = dist(x, y);
        if(r <= 2*2) score+=5;
        else if(r <= 4*4) score+=4;
        else if(r <= 6*6) score+=3;
        else if(r <= 8*8) score+=2;
        else if(r <= 10*10) score+=1;
    }
    cout << score << endl;
    return 0;
}
