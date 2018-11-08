#include <iostream>

using namespace std;

void remove_quotes(char* src, char *dest)
{
    while(*src != '\0') {
        if(*src != '\"' && *src != '\'')
            *(dest++) = *src;
        *(src++);
    }
    *dest = '\0';
}

int main()
{
    char st[1000];
    char out[1000];
    int l;

    cin.getline(st,1000);
    remove_quotes(st,out);

    cout << out << endl;
    return 0;
}
