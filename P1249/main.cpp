#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int shortestPath(int** warMap, int** cache, int mapSize, int x, int y);

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

int shortestPath2(int** warMap, int** cache, int mapSize, int x, int y)
{
    priority_queue<pair<int, pair<int, int> > > dijkstraQueue;

    int** visited = new int*[mapSize];
    for(int i = 0; i < mapSize; i++)
    {
        visited[i] = new int[mapSize];
        memset(visited[i],NOT_VISITED,sizeof(int)*mapSize);
    }

    dijkstraQueue.push(make_pair(0,make_pair(0,0)));
    cache[0][0] = 0;

    while(!dijkstraQueue.empty())
    {
        pair<int, pair<int,int> > target = dijkstraQueue.top();
        pair<int, int> targetPt = target.second;
        dijkstraQueue.pop();
        visited[targetPt.first][targetPt.second] = VISITED;

        for(int i = 0; i < 4; i++)
        {
            int nextX = targetPt.first + pX[i];
            int nextY = targetPt.second + pY[i];

            if(nextX >= 0 && nextX < mapSize &&
                    nextY >= 0 && nextY < mapSize && visited[nextX][nextY])
            {
                cache[nextX][nextY] = min(cache[nextX][nextY], cache[targetPt.first][targetPt.second] + warMap[nextX][nextY]);

                int target = shortestPath(warMap,cache,mapSize, nextX, nextY) + warMap[x][y];
                answer = min(answer,target);
            }
        }
    }

}
