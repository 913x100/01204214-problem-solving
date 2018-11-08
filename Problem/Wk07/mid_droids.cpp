#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct node
{
    int id, pos, status;

    bool operator<(const node a) const
    {
        return pos < a.pos;
    }
};

node robot[100100];

int main()
{
    int n, m, x, pos, res=0;
    scanf("%d %d", &n, &m);
    robot[0] = {0, -1<<28, -1};
    robot[1] = {0, -1<<29, -1};
    for(int i=2; i<=n+1; i++)
    {
        scanf("%d", &pos);
        robot[i] = {i, pos, -1};
        /*scanf("%d", &x);
        robot.push_back(node{i+1, pos, 0});*/
    }
    robot[n+2] = {n+1, 1<<29, 0};
    sort(robot, robot+n+2);
    //for(int i=0; i<=n+2)
    for(int i=0; i<m; i++)
    {
        scanf("%d", &x);
        node stupid = {0, x, -1};
        int p = lower_bound(robot, robot+n+2, stupid)-robot;
        //printf("%d %d\n", robot[p].id, robot[p].pos);
        if(robot[p].pos == x || abs(robot[p-1].pos-x) > abs(robot[p].pos-x))
        {
            if(robot[p].status != i)
            {
                res += abs(robot[p].pos-x);
                robot[p].status = i+1;
                //printf("a%d %d\n", abs(robot[p].pos-x), res);
            }
            else
            {
                if( abs(robot[p-1].pos-x) <= abs(robot[p+1].pos-x) )
                {
                    res += abs(robot[p-1].pos-x);
                    robot[p-1].status = i+1;
                    //printf("b%d %d\n", abs(robot[p-1].pos-x), res);
                }
                else
                {
                    res += abs(robot[p+1].pos-x);
                    robot[p+1].status = i+1;
                    //printf("c%d %d\n", abs(robot[p+1].pos-x), res);
                }
            }
        }
        else
        {
            if( abs(robot[p-1].pos-x) <= abs(robot[p].pos-x) )
            {
                if(robot[p-1].status != i)
                {
                    res += abs(robot[p-1].pos-x);
                    robot[p-1].status = i+1;
                    //printf("d%d %d\n", abs(robot[p-1].pos-x), res);
                }
                else
                {
                    if( abs(robot[p-2].pos-x) <= abs(robot[p].pos-x) )
                    {
                        res += abs(robot[p-2].pos-x);
                        robot[p-2].status = i+1;
                        //printf("e%d %d\n", abs(robot[p-2].pos-x), res);
                    }
                    else
                    {
                        res += abs(robot[p].pos-x);
                        robot[p].status = i+1;
                        //printf("f%d %d\n", abs(robot[p].pos-x), res);
                    }
                }
            }
        }
        //printf("xx%d\n", res);
    }
    printf("%d\n", res);

}
