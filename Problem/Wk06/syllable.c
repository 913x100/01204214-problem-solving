#include<stdio.h>
#include<string.h>
char word[40];
int main()
{
    int len,i,n,count=0,check;
    scanf("%d",&n);
    while(n--)
    {
        check=1;
        count=0;
        scanf("%s",word);
        len=strlen(word);
        for(i=0;i<len;i++)
        {
            if((word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u') && check)
            {
                check=0;
                count++;
            }
            else if(word[i]!='a'&&word[i]!='e'&&word[i]!='i'&&word[i]!='o'&&word[i]!='u')
                check=1;
        }
        printf("%d\n",count);
    }
}

