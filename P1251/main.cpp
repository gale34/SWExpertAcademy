#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

double minRoute(vector<pair<int, int> >& islands);
double calculateDist(pair<int,int>& a, pair<int,int>& b);

int main()
{
    freopen("input.txt","r",stdin);

    int testCase;
    cin >> testCase;

    for(int i = 0; i < testCase; i++)
    {
        int numIsland;
        cin >> numIsland;

        vector<pair<int, int> > islands(numIsland);

        for(int j = 0; j < numIsland; j++)
        {
            int temp;
            cin >> temp;
            islands[j].first = temp;
        }

        for(int j = 0; j < numIsland; j++)
        {
            int temp;
            cin >> temp;
            islands[j].second = temp;
        }

        double taxRate;
        cin >> taxRate;

        long long answer = floor(taxRate * minRoute(islands) + 0.5);

        cout << "#" << i+1 << " " << answer << endl;
    }

    return 0;
}

double minRoute(vector<pair<int, int> >& islands)
{
    int numIsland = islands.size();

    const double INF = 9000000000000;

    vector<bool> visited(numIsland,false);
    vector<double> minDist(numIsland,INF);

    double answer = 0;

    minDist[0] = 0;
    for(int i = 0; i < numIsland; i++)
    {
        int target = -1;

        for(int j = 0; j < numIsland; j++)
        {
            if(!visited[j] && (target == -1 || minDist[target] > minDist[j]))
                target = j;
        }

        answer += minDist[target];
        visited[target] = true;

        for(int j = 0; j < numIsland; j++)
        {
            double cost = calculateDist(islands[target],islands[j]);
            if(!visited[j] && minDist[j] > cost)
                minDist[j] = cost;
        }
    }


    return answer;
}

double calculateDist(pair<int,int>& a, pair<int,int>& b)
{
    return pow((a.first - b.first),2.0) + pow((a.second - b.second),2.0);
}
