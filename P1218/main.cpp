#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

bool isValidBrackets(vector<char> brackets);

int main()
{
    freopen("input.txt","r",stdin);

    for(int i = 0; i < 10; i++)
    {
        int testSize;
        vector<char> brackets;

        cin >> testSize;

        for(int j = 0; j < testSize; j++)
        {
            char temp;
            cin >> temp;
            brackets.push_back(temp);
        }
    }
    cout << "Hello world!" << endl;
    return 0;
}

bool isValidBrackets(vector<char> brackets)
{
    stack<char> bracketStack;

    for(int i = 0; i < brackets.size(); i++)
}
