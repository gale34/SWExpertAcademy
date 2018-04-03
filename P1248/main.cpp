#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

int getParentSize(vector<vector<int> >& tree, int target);
int getSameParent(vector<int>& parentWChild, int target1, int target2);
vector<int> parents(vector<int>& parentWChild, int target);

int main()
{
    freopen("input.txt","r",stdin);

    int testCase;
    cin >> testCase;

    for(int tIdx = 1; tIdx <= testCase; tIdx++)
    {
        int v, e, target1, target2;
        cin >> v >> e >> target1 >> target2;

        vector<vector<int> > tree(v+1);
        vector<int> parentWChild(v+1,0);

        for(int i = 0; i < e; i++)
        {
            int parent, child;
            cin >> parent >> child;

            parentWChild[child] = parent;
            tree[parent].push_back(child);
        }

        int sameParent = getSameParent(parentWChild,target1,target2);
        int parentSize = getParentSize(tree, sameParent);

        cout << "#" << tIdx << " " << sameParent << " " << parentSize << endl;
    }

    return 0;
}

int getParentSize(vector<vector<int> >& tree, int target)
{
    queue<int> countQueue;
    countQueue.push(target);
    int result = 0;

    while(!countQueue.empty())
    {
        int subTarget = countQueue.front();
        countQueue.pop();
        result++;

        for(int i = 0; i < tree[subTarget].size(); i++)
            countQueue.push(tree[subTarget][i]);
   }

   return result;
}

int getSameParent(vector<int>& parentWChild, int target1, int target2)
{
    vector<int> target1Parents = parents(parentWChild, target1);
    vector<int> target2Parents = parents(parentWChild, target2);

    for(int i = 0; i < target1Parents.size(); i++)
    {
        for(int j = 0; j < target2Parents.size(); j++)
        {
            if(target1Parents[i] == target2Parents[j])
                return target1Parents[i];
        }
    }

    return 0;
}

vector<int> parents(vector<int>& parentWChild, int target)
{
    vector<int> parents;
    int parent = parentWChild[target];

    while(parent != 0)
    {
        parents.push_back(parent);
        parent = parentWChild[parent];
    }

    return parents;
}
