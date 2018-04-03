#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int shortestPath(int** warMap, int** cache, int mapSize, int x, int y);

#define INF 999999

int pX[4] = {0,1,0,-1};
int pY[4] = {1,0,-1,0};
int main()
{
    freopen("input.txt","r",stdin);

    int testCase;
    cin >> testCase;

    for(int testIdx = 1; testIdx <= testCase; testIdx++)
    {
        int mapSize;
        cin >> mapSize;

        int** warMap = new int*[mapSize];
        int** cache = new int*[mapSize];
        for(int i = 0; i < mapSize; i++)
        {
            warMap[i] = new int[mapSize];
            cache[i] = new int[mapSize];
            memset(warMap[i],0,sizeof(int)*mapSize);

            for(int j = 0; j < mapSize; j++)
                cache[i][j] = INF;
        }

        for(int i = 0; i < mapSize; i++)
        {
            for(int j = 0; j < mapSize; j++)
            {
                char temp;
                cin >> temp;
                warMap[i][j] = (int)temp - 48;
            }
        }

        int answer = shortestPath(warMap, cache, mapSize, 0, 0);

        for(int i = 0; i < mapSize; i++)
        {
            for(int j = 0; j < mapSize; j++)
            {
                cout << cache[i][j] << " ";
            }
            cout << endl;
        }

        cout << "#" << testIdx << " " << answer << endl;

        for(int i = 0; i < mapSize; i++)
        {
             delete warMap[i];
             delete cache[i];
        }
        delete warMap;
        delete cache;
    }
    return 0;
}

int shortestPath(int** warMap, int** cache, int mapSize, int x, int y)
{
    int& answer = cache[x][y];

    if(answer != INF)
        return answer;

    if(x == mapSize - 1 && y == mapSize - 1)
        return answer = warMap[x][y];

    for(int i = 0; i < 4; i++)
    {
        int nextX = x + pX[i];
        int nextY = y + pY[i];

        if(nextX >= 0 && nextX < mapSize &&
           nextY >= 0 && nextY < mapSize)
        {
            int target = shortestPath(warMap,cache,mapSize, nextX, nextY) + warMap[x][y];
            answer = min(answer,target);
        }

    }

    return answer;
}
