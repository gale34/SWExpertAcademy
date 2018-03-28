#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

void printInorder(vector<char>& tree, int target);

int main()
{
    freopen("input.txt","r",stdin);

    for(int i = 0; i < 10; i++)
    {
        int nodeSize;
        cin >> nodeSize;

        vector<char> tree(nodeSize+1,'\0');

        for(int j = 0; j < nodeSize; j++)
        {
            int idx;
            char value;
            int left, right;

            cin >> idx;
            cin >> value;

            if(idx*2 <= nodeSize)
                cin >> left;
            if((idx*2+1) <= nodeSize)
                cin >> right;

            tree[idx] = value;
        }

        cout << "#" << i+1 << " ";
        printInorder(tree, 1);
        cout << endl;
    }
    return 0;
}

void printInorder(vector<char>& tree, int target)
{
    int treeSize = tree.size()-1;

    if(target > treeSize)
        return ;

    if(target*2 <= treeSize)
        printInorder(tree, target*2);
    cout << tree[target];
    if((target*2 + 1) <= treeSize)
        printInorder(tree, target*2+1);
}
