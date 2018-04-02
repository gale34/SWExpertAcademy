#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int shortcut(vector<int>& path, int** dist, bool* visited, int buildingSize, int nowDist);

int main()
{
    freopen("input.txt","r",stdin);

    int testCase;
    cin >> testCase;

    for(int i = 0; i < testCase; i++)
    {
        int numOfcustomer;
        cin >> numOfcustomer;

        vector<pair<int,int> > building;

        pair<int, int> company;
        cin >> company.first >> company.second;
        building.push_back(company);

        pair<int, int> home;
        cin >> home.first >> home.second;

        for(int j = 0; j < numOfcustomer; j++)
        {
            pair<int, int> temp;
            cin >> temp.first >> temp.second;

            building.push_back(temp);
        }

        building.push_back(home);

        int** dist;
        dist = new int*[numOfcustomer+2];
        for(int j = 0; j < numOfcustomer+2; j++)
        {
            dist[j] = new int[numOfcustomer+2];
            memset(dist[j],0,numOfcustomer+2);
        }

        for(int j = 0; j < numOfcustomer+2; j++)
            for(int k = j; k < numOfcustomer+2; k++)
            {
                dist[j][k] = abs(building[j].first - building[k].first) + abs(building[j].second - building[k].second);
                dist[k][j] = dist[j][k];
            }

        bool* visited = new bool[numOfcustomer+2];
        memset(visited,false,numOfcustomer+2);

        vector<int> path;
        path.push_back(0);

        int answer = shortcut(path, dist, visited, numOfcustomer, 0);

        cout << "#" << i+1 << " " << answer << endl;

        delete visited;
        for(int j = 0; j < numOfcustomer+2; j++)
            delete dist[j];
        delete dist;
    }
    return 0;
}

int shortcut(vector<int>& path, int** dist, bool* visited, int buildingSize, int nowDist)
{
    if(path.size() == buildingSize+1)
        return nowDist + dist[path.back()][buildingSize+1];

    int answer = 9999999;

    for(int i = 1; i <= buildingSize; i++)
    {
        if(visited[i])
            continue;

        int target = path.back();
        path.push_back(i);

        visited[i] = true;

        int cmpDist = shortcut(path,dist,visited,buildingSize,nowDist + dist[target][i]);
        answer = min(answer, cmpDist);

        visited[i] = false;
        path.pop_back();
    }

    return answer;
}
