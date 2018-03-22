#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>

#define PARENTHESIS 1
#define BRACKET 2
#define BRACE 3
#define ANGLE_BRACKET 4

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

        bool result = isValidBrackets(brackets);

        cout << "#" << i+1 << " ";
        if(result)
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }

    return 0;
}

bool isValidBrackets(vector<char> brackets)
{
    stack<int> bracketStack;

    for(int i = 0; i < brackets.size(); i++)
    {
        if(brackets[i] == '(')
            bracketStack.push(PARENTHESIS);
        else if(brackets[i] == '[')
            bracketStack.push(BRACKET);
        else if(brackets[i] == '{')
            bracketStack.push(BRACE);
        else if(brackets[i] == '<')
            bracketStack.push(ANGLE_BRACKET);
        else
        {
            if(bracketStack.empty())
                return false;

            int target = bracketStack.top();

            if(brackets[i] == ')')
            {
                if(target == PARENTHESIS)
                    bracketStack.pop();
                else
                    return false;
            }
            else if(brackets[i] == ']')
            {
                if(target == BRACKET)
                    bracketStack.pop();
                else
                    return false;
            }
            else if(brackets[i] == '}')
            {
                if(target == BRACE)
                    bracketStack.pop();
                else
                    return false;
            }
            else if(brackets[i] == '>')
            {
                if(target == ANGLE_BRACKET)
                    bracketStack.pop();
                else
                    return false;
            }
        }
    }

    if(!bracketStack.empty())
        return false;

    return true;
}
