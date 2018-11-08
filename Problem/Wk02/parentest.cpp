#include <cstdio>
#include <stack>

using namespace std;

char str[105];

stack<char> st;

int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", str);
        st.push(str[0]);
        for(int i=1; str[i]!='\0'; i++) {
            if(!st.empty() && st.top() == '(' && str[i] == ')')
                st.pop();
            else if(!st.empty() && st.top() == '[' && str[i] == ']')
                st.pop();
            else if(!st.empty() && st.top() == '{' && str[i] == '}')
                st.pop();
            else
                st.push(str[i]);
        }

        if(st.empty())
            printf("yes\n");
        else
            printf("no\n");
        while(!st.empty()) st.pop();
    }
    return 0;
}
