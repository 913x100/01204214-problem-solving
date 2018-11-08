#include<stdio.h>
int root[100100],height[100100];
int find(int n)
{
    int node=n,par;
    while(root[n]!=n)
        n=root[n];
    while(node!=n)
    {
        par=root[node];
        root[node]=n;
        node=par;
    }
    return n;
}
int main()
{
    int i,n,q,a,b,A,B;
    char ch;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++)
        root[i]=i;
    while(q--)
    {
        scanf(" %c",&ch);
        scanf("%d %d",&a,&b);
        A=find(a);
        B=find(b);
        if(ch=='q')
        {
            if(A==B)    printf("yes\n");
            else    printf("no\n");
        }
        else
        {
            if(height[A]>height[B]) root[B]=A;
            else if(height[A]<height[B])    root[A]=B;
            else
            {
                root[A]=B;
                height[B]++;
            }
        }
    }
}
/*
5 10
q 1 2
c 1 3
q 3 2
c 3 2
q 1 2
q 4 5
c 4 2
q 4 1
c 1 4
q 5 1
*/
