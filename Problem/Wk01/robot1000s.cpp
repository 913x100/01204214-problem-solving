#include <iostream>
#include <cmath>

using namespace std;

string cmd;

int main()
{
    int N=0, S=0, E=0, W=0, k;
    cin >> cmd;
    cin >> k;
    for(int i=0; cmd[i]!='\0'; i++){
        if(cmd[i] == 'N') N++;
        else if(cmd[i] == 'S') S++;
        else if(cmd[i] == 'E') E++;
        else if(cmd[i] == 'W') W++; 
    }
    while(k--) {
        if(N > 0 && S > N) N--;
        else if(S > 0 && N > S) S--;
        else if(W > 0 && E > W) W--;
        else if(E > 0 && W > E) E--;
        else if(N == 0 && S > 0) S--;
        else if(S == 0 && N > 0) N--;
        else if(E == 0 && W > 0) W--;
        else if(W == 0 && E > 0) E--;
    }
    cout << (abs(N-S)+abs(W-E))*2 << endl;

    return 0;
}
