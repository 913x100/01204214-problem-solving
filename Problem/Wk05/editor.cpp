#include <iostream>
#include <list>
#include <string>

using namespace std;

list<string> l;
list<string>::iterator it;
list<string>::iterator it1;

int main()
{
    int n;
    char cmd;
    string str;
    cin >> n;
    it = l.begin();
    while(n--)
    {
        cin >> cmd;
        if(cmd == 'i')
        {
            cin >> str;
            l.insert(it, str);
        }
        else if(cmd == 'l')
        {
            if(it != l.begin())
                it--;
        }
        else if(cmd == 'r')
        {
            if(it != l.end())
                it++;
        }
        else if(cmd == 'b')
        {
            if(it != l.begin()) {
                it--;
                it=l.erase(it);
            }
        }
        else if(cmd == 'd')
        {
            if(it != l.end())
                it=l.erase(it);
        }
        /*for(it1=l.begin(); it1!=l.end(); it1++)
        {
            cout << *it1 << " ";
        }
        cout << "it=" << *it << endl;*/
    }
    for(it1=l.begin(); it1!=l.end(); it1++)
    {
        cout << *it1 << " ";
    }

    return 0;
}

