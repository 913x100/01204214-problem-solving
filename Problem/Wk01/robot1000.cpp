#include <iostream>
#include <string>

using namespace std;

string cmd;

int main()
{
    int x=0, y=0;
    cin >> cmd;
    for(int i=0; i<cmd.size(); i++)
    {
        switch(cmd[i]) {
            case 'N': y++; break;
            case 'S': y--; break;
            case 'E': x++; break;
            case 'W': x--; break;  
            case 'Z': x=0, y=0; break;
        }
    }
    cout << x << " " << y << endl;

    return 0;
}
