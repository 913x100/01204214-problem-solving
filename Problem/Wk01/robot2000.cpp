#include <iostream>
#include <cmath>

using namespace std;

char str[105], status='N';

int main()
{
    cin >> str;
    for(int i=0; str[i]!='\0'; i++) {
        if(str[i] == 'Z') {
            cout << 'Z';
            status = 'N';
            continue;
        }
        switch(status) {
            case 'N': 
                if(str[i] == 'N') cout << "F";
                else if(str[i] == 'E') cout << "RF";
                else if(str[i] == 'S') cout << "RRF";
                else if(str[i] == 'W') cout << "RRRF";
            break;
            case 'E': 
                if(str[i] == 'E') cout << "F";
                else if(str[i] == 'S') cout << "RF";
                else if(str[i] == 'W') cout << "RRF";
                else if(str[i] == 'N') cout << "RRRF";
            break;
            case 'S': 
                if(str[i] == 'S') cout << "F";
                else if(str[i] == 'W') cout << "RF";
                else if(str[i] == 'N') cout << "RRF";
                else if(str[i] == 'E') cout << "RRRF";
            break;
            case 'W': 
                if(str[i] == 'W') cout << "F";
                else if(str[i] == 'N') cout << "RF";
                else if(str[i] == 'E') cout << "RRF";
                else if(str[i] == 'S') cout << "RRRF";
            break;
        }
        status = str[i];
    }
    return 0;
}
