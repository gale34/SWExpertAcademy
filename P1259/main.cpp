#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector<int> linkScrews(vector<vector<int> >& screwGraph);
vector<int> dfs(vector<vector<int> >& screwGraph, vector<int> link, vector<bool>& visited, int target);

int main()
{
    freopen("input.txt","r",stdin);

    int testCase;
    cin >> testCase;

    for(int t = 0; t < testCase; t++)
    {
        int numScrew;
        cin >> numScrew;

        vector<pair<int, int> > screws;
        vector<vector<int> > screwGraph(numScrew);

        for(int i = 0; i < numScrew; i++)
        {
            int start, last;
            cin >> start >> last;
            screws.push_back(make_pair(start, last));
        }

        for(int i = 0; i < numScrew; i++)
        {
            int target = screws[i].second;
            for(int j = 0; j < numScrew; j++)
            {
                if(i == j)
                    continue;

                if(target == screws[j].first)
                    screwGraph[i].push_back(j);
            }
        }

        vector<int> result = linkScrews(screwGraph);

        cout << "#" << t+1 << " ";
        for(int i = 0; i < result.size(); i++)
        {
            int target = result[i];
            cout << screws[target].first << " " << screws[target].second << " ";
        }
        cout << endl;
    }

    return 0;
}

vector<int> linkScrews(vector<vector<int> >& screwGraph)
{
    int numScrew = screwGraph.size();
    vector<int> result;

    for(int i = 0; i < numScrew; i++)
    {
        vector<int> link;
        vector<bool> visited = vector<bool>(numScrew, false);

        link = dfs(screwGraph, link, visited, i);

        if(result.size() < link.size())
            result = link;
    }

    return result;
}

vector<int> dfs(vector<vector<int> >& screwGraph, vector<int> link, vector<bool>& visited, int target)
{
    link.push_back(target);
    visited[target] = true;
    vector<int> result(link);

    for(int i = 0; i < screwGraph[target].size(); i++)
    {
        vector<int> tempLink;
        int subTarget= screwGraph[target][i];
        if(!visited[subTarget])
            tempLink = dfs(screwGraph, link, visited, subTarget);

        if(result.size() < tempLink.size())
            result = tempLink;
    }

    visited[target] = false;
    return result;
}
