#include <iostream>
#include <cstdio>

using namespace std;

#define LADDER_SIZE 100
#define TEST_CASE 10
#define TO_LEFT -1
#define TO_RIGHT 1
#define TO_DOWN 0

int getDistPt(int ladder[][LADDER_SIZE], pair<int, int> now, int way);

int main()
{
    freopen("input.txt","r",stdin);

    for(int i = 0; i < TEST_CASE; i++)
    {
        int ladder[LADDER_SIZE][LADDER_SIZE];
        int dest;

        int test_case;
        cin >> test_case;

        for(int j = 0 ; j < 100; j++)
            for(int k = 0; k < 100; k++)
                cin >> ladder[j][k];

        int min_result = 10001;
        int result = 0;
        int answer = 0;

        for(int j = 0; j < 100; j++)
        {
            if(ladder[0][j] == 0)
                continue;

            result = getDistPt(ladder, make_pair(0,j), 0);

            if(result <= min_result)
            {
                min_result = result;
                answer = j;
            }
        }

        cout << "#" << test_case << " " << answer << endl;
    }

    return 0;
}

int getDistPt(int ladder[][LADDER_SIZE], pair<int,int> now, int way)
{
    if(now.first == LADDER_SIZE - 1)
        return 0;

    if(now.second > 0 && way != TO_RIGHT && ladder[now.first][now.second-1] == 1)
        return 1 + getDistPt(ladder, make_pair(now.first,now.second-1), TO_LEFT);
    else if(now.second < LADDER_SIZE-1 && way != TO_LEFT && ladder[now.first][now.second+1] == 1)
        return 1 + getDistPt(ladder, make_pair(now.first,now.second+1), TO_RIGHT);
    else
        return 1 + getDistPt(ladder, make_pair(now.first+1,now.second), TO_DOWN);
}
