#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define START 0
#define DEST 99
#define ROUTE_SIZE 100

using namespace std;

bool isConnectedRoutes(vector<int> route[ROUTE_SIZE]);

int main()
{
    freopen("input.txt","r",stdin);

    for(int i = 0; i < 10; i++)
    {
        int testCase;
        int numOfRoute;

        vector<int> route[ROUTE_SIZE];
        cin >> testCase >> numOfRoute;

        for(int j = 0; j < numOfRoute; j++)
        {
            int start, dest;

            cin >> start >> dest;

            route[start].push_back(dest);
        }

        bool result = isConnectedRoutes(route);

        cout << "#" << i+1 << " ";
        if(result)
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }

    return 0;
}

bool isConnectedRoutes(vector<int> route[ROUTE_SIZE])
{
    vector<int> dist(ROUTE_SIZE,0);
    queue<int> routeQueue;

    routeQueue.push(START);

    while(!routeQueue.empty())
    {
        int target = routeQueue.front();
        routeQueue.pop();

        if(dist[target] != 0)
            continue;

        dist[target] = 1;


        for(int i = 0; i < route[target].size(); i++)
        {
            int subTarget = route[target][i];
            if(dist[subTarget] == 0)
                routeQueue.push(subTarget);
        }
    }

    if(dist[DEST] == 1)
        return true;
    else
        return false;
}
