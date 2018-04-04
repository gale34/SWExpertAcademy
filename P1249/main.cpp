#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int shortestPath(int** warMap, int** cache, int mapSize);

#define INF 999999
#define VISITED 1
#define NOT_VISITED 0

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

        int answer = shortestPath2(warMap, cache, mapSize);

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

int shortestPath(int** warMap, int** cache, int mapSize)
{
    priority_queue<pair<int, pair<int, int> > > dijkstraQueue;

    dijkstraQueue.push(make_pair(0,make_pair(0,0)));
    cache[0][0] = 0;

    while(!dijkstraQueue.empty())
    {
        pair<int, pair<int,int> > target = dijkstraQueue.top();
        int dist = -target.first;
        pair<int, int> targetPt = target.second;
        dijkstraQueue.pop();

        if(cache[targetPt.first][targetPt.second] < dist)
            continue;

        for(int i = 0; i < 4; i++)
        {
            int nextX = targetPt.first + pX[i];
            int nextY = targetPt.second + pY[i];

            if(nextX >= 0 && nextX < mapSize &&
                    nextY >= 0 && nextY < mapSize)
            {
                int nextDist = dist + warMap[nextX][nextY];

                if(cache[nextX][nextY] > nextDist)
                {
                    cache[nextX][nextY] = nextDist;
                    dijkstraQueue.push(make_pair(-nextDist,make_pair(nextX,nextY)));
                }
            }
        }
    }

    return cache[mapSize-1][mapSize-1];
}
