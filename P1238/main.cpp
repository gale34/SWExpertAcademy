#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define MAX_PERSON_SIZE 100

using namespace std;

void contactNumbers(vector<int> contacts[MAX_PERSON_SIZE+1],int* visited, int start);
int getMaxNumber(int* visited);

int main()
{
    freopen("input.txt","r",stdin);

    for(int i = 0; i < 10; i++)
    {
        vector<int> contacts[MAX_PERSON_SIZE+1];

        int visited[MAX_PERSON_SIZE+1] = {};
        fill_n(visited,MAX_PERSON_SIZE+1,-1);

        int commandSize;
        int first;

        cin >> commandSize >> first;

        for(int j = 0; j < commandSize/2; j++)
        {
            int start, dest;
            cin >> start >> dest;

            contacts[start].push_back(dest);
        }

        contactNumbers(contacts,visited,first);
        int result = getMaxNumber(visited);

        cout << "#" << i+1 << " " << result << endl;
    }

    return 0;
}

void contactNumbers(vector<int> contacts[MAX_PERSON_SIZE+1],int* visited, int start)
{
    queue<pair<int, int> > orderQueue;
    int order = 1;

    orderQueue.push(make_pair(order,start));
    visited[start] = order;

    while(!orderQueue.empty())
    {
        pair<int, int> target = orderQueue.front();
        orderQueue.pop();
        int targetOrder = target.first;
        int targetIdx = target.second;

        for(int i = 0; i < contacts[targetIdx].size(); i++)
        {
            int subTargetIdx = contacts[targetIdx][i];

            if(visited[subTargetIdx] < 0)
            {
                visited[subTargetIdx] = targetOrder+1;
                orderQueue.push(make_pair(targetOrder+1,subTargetIdx));
            }
        }
    }
}

int getMaxNumber(int* visited)
{
    int maxValue = 0;
    int result = 0;

    for(int i = 0; i < MAX_PERSON_SIZE+1; i++)
    {
        if(maxValue <= visited[i])
        {
            maxValue = visited[i];
            result = i;
        }
    }

    return result;
}
