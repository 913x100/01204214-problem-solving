#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct team {
    string name;
    int score, win, lost, diff;

    bool operator<(const team &a)const
    {
        if(score == a.score) {
            if(diff == a.diff) return win > a.win;
            return diff > a.diff;
        }
        return score > a.score;
    }
};

team a[5];
int tmp[5][5];


int main()
{
    int x;
    for(int i=0; i<4; i++) {
        a[i].score = a[i].win = a[i].lost = a[i].diff = 0;
        cin >> a[i].name;
    }
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            cin >> tmp[i][j];
            a[i].win += tmp[i][j];
            a[j].lost += tmp[i][j];
        }
    }
    for(int i=0; i<4; i++) {
        for(int j=i+1; j<4; j++) {
            if(tmp[i][j] > tmp[j][i])
                a[i].score += 3;
            else if(tmp[i][j] < tmp[j][i])
                a[j].score += 3;
            else {
                a[i].score += 1;
                a[j].score += 1;
            }
        }
    }
    for(int i=0; i<4; i++)
        a[i].diff = a[i].win - a[i].lost;

    sort(a, a+4);
    for(int i=0; i<4; i++)
        cout << a[i].name << " " << a[i].score << endl;

    return 0;
}
