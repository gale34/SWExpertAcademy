#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <queue>

using namespace std;

struct node
{
    double value;
    char opt;
    bool isOpt;
    int left;
    int right;
};

bool isWrong;
node dataSplit(string target);
double operateTree(vector<node>& tree, int pt);
vector<string> splitSpace(string target);

int main()
{
    freopen("input.txt","r",stdin);

    for(int i = 0; i < 10; i++)
    {
        int nodeSize;
        cin >> nodeSize;

        vector<node> tree;

        tree.resize(nodeSize+1);

        for(int j = 0; j < nodeSize; j++)
        {
            int idx;
            cin >> idx;

            string value;
            getline(cin,value);

            tree[idx] = dataSplit(value);
        }

        isWrong = false;
        int answer = operateTree(tree, 1);

        cout << "#" << i+1 << " ";
        if(isWrong)
            cout << "0" << endl;
        else
            cout << "1" << endl;
    }
    return 0;
}

node dataSplit(string target)
{
    vector<string> splitValue = splitSpace(target);

    node newNode;

    if(splitValue[0].find("+") != string::npos)
    {
        newNode.isOpt = true;
        newNode.opt = '+';
        newNode.value = 0.0;
    }
    else if(splitValue[0].find("-") != string::npos)
    {
        newNode.isOpt = true;
        newNode.opt = '-';
        newNode.value = 0.0;
    }
    else if(splitValue[0].find("*") != string::npos)
    {
        newNode.isOpt = true;
        newNode.opt = '*';
        newNode.value = 0.0;
    }
    else if(splitValue[0].find("/") != string::npos)
    {
        newNode.isOpt = true;
        newNode.opt = '/';
        newNode.value = 0.0;
    }
    else
    {
        newNode.isOpt = false;
        newNode.opt = 'N';
        newNode.value = (double)atoi(splitValue[0].c_str());
    }

    if(splitValue.size() > 2)
        newNode.left = atoi(splitValue[1].c_str());
    else
        newNode.left = 0;

    if(splitValue.size() > 3)
        newNode.right = atoi(splitValue[2].c_str());
    else
        newNode.right = 0;

    return newNode;
}

double operateTree(vector<node>& tree, int pt)
{
    if(isWrong == true)
        return 0;

    node* target = &tree[pt];

    if(target->isOpt == false)
    {
        if(target->left != 0 || target->right != 0)
        {
            isWrong = true;
            return 0;
        }
        return target->value;
    }

    if(target->left == 0 || target->right == 0)
    {
        isWrong = true;
        return 0;
    }

    if(target->opt == '+')
        return operateTree(tree,target->left) + operateTree(tree,target->right);
    else if(target->opt == '-')
        return operateTree(tree,target->left) - operateTree(tree,target->right);
    else if(target->opt == '*')
        return operateTree(tree,target->left) * operateTree(tree,target->right);
    else if(target->opt == '/')
        return operateTree(tree,target->left) / operateTree(tree,target->right);
}

vector<string> splitSpace(string target)
{
    vector<string> result;
    istringstream iss(target);

    while(iss)
    {
        string subTarget;
        iss >> subTarget;
        result.push_back(subTarget);
    }

    return result;
}
