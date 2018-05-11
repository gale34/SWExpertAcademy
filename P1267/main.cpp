#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector<int> workProcess(vector<vector<int> >& edge);
void dfs(vector<int>& result, bool* visited, vector<vector<int> >& edge, int target);

int main()
{
    freopen("input.txt","r",stdin);

    for(int t = 0; t < 10; t++)
    {
        int v, e;
        cin >> v >> e;

        vector<vector<int> > edge(v);

        for(int i = 0; i < e; i++)
        {
            int start, finish;

            cin >> start >> finish;

            edge[start-1].push_back(finish-1);
        }

        vector<int> result = workProcess(edge);

        cout << "#" << t+1 << " ";

        for(int i = result.size() - 1; i >= 0 ; i--)
            cout << result[i]+1 << " ";
        cout << endl;

    }

    return 0;
}

vector<int> workProcess(vector<vector<int> >& edge)
{
    int workSize = edge.size();
    vector<int> result;
    bool* visited = new bool[workSize];
    for(int i = 0; i < workSize; i++)
        visited[i] = false;

    for(int i = 0; i < workSize; i++)
    {
        if(!visited[i])
            dfs(result, visited, edge, i);
    }

    return result;
}

void dfs(vector<int>& result, bool* visited, vector<vector<int> >& edge, int target)
{
    visited[target] = true;

    for(int i = 0; i < edge[target].size(); i++)
    {
        if(!visited[edge[target][i]])
            dfs(result, visited, edge, edge[target][i]);
    }

    result.push_back(target);
}
