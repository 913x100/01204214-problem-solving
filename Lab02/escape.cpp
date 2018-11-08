#include <iostream>

using namespace std;

char* write_chars(char* dest, const char* st)
{
    while(*st != '\0') {
        *(dest++) = *(st++);
    }
    //*dest = '\0';
    //cout << *(dest) << endl;
    return dest;
}

void escape(char* src, char *dest)
{
    while(*src != '\0') {
        if(*src == '<') {
            dest = write_chars(dest, "&lt;");
            *(src++);
        } else if(*src == '>') {
            dest = write_chars(dest, "&gt;");
            *(src++);
        } else if(*src == '\"') {
            dest = write_chars(dest, "&quot;");
            *(src++);
        }
        else
            *(dest++) = *(src++);
    }
    *dest = '\0';
}

int main()
{
    char st[1000];
    char out[1000];
    int l;

    cin.getline(st,1000);
    escape(st,out);

    cout << out << endl;
    return 0;
}
