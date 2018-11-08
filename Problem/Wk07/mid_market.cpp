#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;
struct node{
    int price, cnt;
    bool operator<(const node a)const
    {
        if(price == a.price) return cnt < a.cnt;
        return price > a.price;
    }

};
priority_queue<node> Q, P;

int main()
{
    int num, price;
    int n, cmd, a, b, res=0;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %d %d", &cmd, &a, &b);
        if(cmd == 2) { //Q
            if(P.empty() || P.top().price < a)
                Q.push(node{-1*a, b});
            else {
                while(!P.empty() && b > 0) {
                    price = P.top().price;
                    num = P.top().cnt;
                    P.pop();
                    if(num - b <= 0) {
                        res += a*num;
                        printf("num:%d a:%d a*num:%d\n", num, a, a*num);
                        b -= num;
                    } else {
                        res += b*a;
                        printf("%d\n", a*b);
                        P.push(node{price, num-b});
                        b = 0;
                        break;
                    }
                }
                if(b > 0)
                    Q.push(node{a*-1, b});
            }
        } else if(cmd == 1) { // P
            printf("%d\n", Q.top().price);
            if(Q.empty() || Q.top().price*(-1) > a) {
                P.push(node{a, b});
            }
            else {
                while(!Q.empty() && b > 0) {
                    price = Q.top().price*(-1);
                    num = Q.top().cnt;
                    Q.pop();
                    if(num - b <= 0) {
                        res += a*num;
                        printf("num:%d a:%d a*num:%d\n", num, a, a*num);
                        b -= num;
                    } else {
                        res += b*a;
                        printf("%d\n", a*b);
                        Q.push(node{price*(-1), num-b});
                        b = 0;
                        break;
                    }
                }
                if(b > 0)
                    P.push(node{a, b});
            }
        }
        printf("res=%d\n", res);
    }
    return 0;
}
