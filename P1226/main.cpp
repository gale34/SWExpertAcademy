#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>

#define MAZE_SIZE 16
#define VISIT 1
#define NOT_VISIT 0

int pX[4] = {0,1,0,-1};
int pY[4] = {1,0,-1,0};

using namespace std;

bool isExitable(char maze[][MAZE_SIZE], pair<int, int> start);

int main()
{
    freopen("input.txt","r",stdin);

    for(int i = 0; i < 10; i++)
    {
        int testCase;
        cin >> testCase;

        char maze[MAZE_SIZE][MAZE_SIZE];
        pair<int, int> start;

        for(int j = 0; j < MAZE_SIZE; j++)
        {
            for(int k = 0; k < MAZE_SIZE; k++)
            {
                cin >> maze[j][k];

                if(maze[j][k] == '2')
                    start = make_pair(j,k);

            }
        }

        bool result = isExitable(maze,start);

        cout << "#" << testCase;
        if(result)
            cout << " 1" << endl;
        else
            cout << " 0" << endl;

    }

    return 0;
}

bool isExitable(char maze[][MAZE_SIZE], pair<int, int> start)
{
    vector<vector<int> > isVisited;
    for(int i = 0; i < MAZE_SIZE; i++)
    {
        vector<int> row(MAZE_SIZE,NOT_VISIT);
        isVisited.push_back(row);
    }

    stack<pair<int, int> > routeStack;

    routeStack.push(start);
    isVisited[start.first][start.second] = VISIT;

    while(!routeStack.empty())
    {

        pair<int, int> target = routeStack.top();
        routeStack.pop();
        isVisited[target.first][target.second] = VISIT;

        for(int i = 0; i < 4; i++)
        {
            pair<int, int> next = make_pair(target.first + pX[i],target.second + pY[i]);

            if(next.first >= 0 && next.first < MAZE_SIZE && next.second >= 0 && next.second < MAZE_SIZE && isVisited[next.first][next.second] == NOT_VISIT && maze[next.first][next.second] != '1')
            {
                if(maze[next.first][next.second] == '3')
                    return true;
                routeStack.push(next);
            }
        }
    }

    return false;
}
