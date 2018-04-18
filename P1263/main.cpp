#include <iostream>
#include <vector>
#include <cstdio>

#define INF 9999999

using namespace std;

void floyd(vector<vector<int> >& closeness);

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
            vector<int> temp(numPeople, 0);
            for(int j = 0; j < numPeople; j++)
            {
                cin >> temp[j];
                if(temp[j] == 0 && i != j)
                    temp[j] = INF;
            }
            closeness[i] = temp;
        }

        floyd(closeness);

        /*for(int i = 0; i < numPeople; i++)
        {
            for(int j = 0; j < numPeople; j++)
                cout << closeness[i][j] << " ";
            cout << endl;
        }*/

        int result = INF;
        for(int i = 0; i < numPeople; i++)
        {
            int tempSum = 0;
            for(int j = 0; j < numPeople; j++)
                tempSum += closeness[i][j];

            result = min(result, tempSum);
        }

        cout << "#" << t+1 << " " << result << endl;
    }

    return 0;
}

void floyd(vector<vector<int> >& closeness)
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
}
