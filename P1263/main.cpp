#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

#define INF 9999999

using namespace std;

int getCC(vector<vector<int> >& closeness, int target);

int main()
{
    freopen("input.txt","r",stdin);

    int testCase;
    cin >> testCase;

    for(int t = 0; t < testCase; t++)
    {
        int numPeople;
        cin >> numPeople;

        vector<vector<int> > closeness(numPeople);
        for(int i = 0; i < numPeople; i++)
        {
            for(int j = 0; j < numPeople; j++)
            {
                int temp;
                cin >> temp;
                if(temp == 1)
                    closeness[i].push_back(j);
            }
        }

        int result = INF;
        for(int i = 0; i < numPeople; i++)
            result = min(result,getCC(closeness,i));

        cout << "#" << t+1 << " " << result << endl;
    }

    return 0;
}

int getCC(vector<vector<int> >& closeness, int target)
{
    int numPeople = closeness.size();
    queue<int> ccQ;
    vector<int> added(numPeople,0);

    ccQ.push(target);

    while(!ccQ.empty())
    {
        int subTarget = ccQ.front();
        ccQ.pop();

        for(int i = 0; i < closeness[subTarget].size(); i++)
        {
            int nextTarget = closeness[subTarget][i];

            if(nextTarget == target || added[nextTarget] != 0)
                continue;

            ccQ.push(nextTarget);
            added[nextTarget] = added[subTarget]+1;
        }
    }

    int result = 0;
    for(int i = 0; i < numPeople; i++)
        result += added[i];

    return result;
}

/*void floyd(vector<vector<int> >& closeness)
{
    int numPeople = closeness.size();

    for(int k = 0; k < numPeople; k++)
    {
        for(int i = 0; i < numPeople; i++)
        {
            if(closeness[i][k] >= INF)
                continue;
            for(int j = 0; j < numPeople; j++)
                closeness[i][j] = min(closeness[i][j], closeness[i][k] + closeness[k][j]);
        }
    }
}*/
