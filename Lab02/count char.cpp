#include <iostream>

using namespace std;

int count_char(char* st, char c)
{
    int cnt=0;
    for(int i=0; st[i]!='\0'; i++) {
        if(st[i] == c) cnt++;
    }
    return cnt;
}

int main()
{
    char st[1000];

    cin.getline(st,1000);

    cout << "space: " << count_char(st,' ') << endl;
    cout << "dot: " << count_char(st,'.') << endl;
    cout << "semi: " << count_char(st,';') << endl;
    return 0;
}
