#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

string toPostfix(string infix);
int calculate(string postfix);

int main()
{
    freopen("input.txt","r",stdin);

    for(int i = 0; i < 10; i++)
    {
        int testSize;
        cin >> testSize;

        string infix;
        cin >> infix;

        string postfix = toPostfix(infix);
        int result = calculate(postfix);

        cout << "#" << i+1 << " " << result << endl;
    }
    return 0;
}

string toPostfix(string infix)
{
    string result;
    stack<char> operatorStack;

    for(int i = 0; i < infix.size(); i++)
    {
        char target = infix.at(i);
        if(target >= '0' &&target <= '9')
            result.push_back(target);
        else if(target == '+')
        {
            while(!operatorStack.empty())
            {
                char subTarget = operatorStack.top();

                if(subTarget == '(')
                    break;

                result.push_back(subTarget);
                operatorStack.pop();
            }
            operatorStack.push(target);
        }
        else if(target == '*')
        {
            while(!operatorStack.empty())
            {
                char subTarget = operatorStack.top();

                if(subTarget == '+' || subTarget == '(')
                    break;

                result.push_back(subTarget);
                operatorStack.pop();
            }
            operatorStack.push(target);
        }
        else if(target == '(')
            operatorStack.push(target);
        else if(target == ')')
        {
            char subTarget = operatorStack.top();

            while(subTarget != '(')
            {
                result.push_back(subTarget);
                operatorStack.pop();

                subTarget = operatorStack.top();
            }

            operatorStack.pop();
        }
    }

    while(!operatorStack.empty())
    {
        result.push_back(operatorStack.top());
        operatorStack.pop();
    }

    return result;
}

int calculate(string postfix)
{
    stack<int> result;

    for(int i = 0; i < postfix.size(); i++)
    {
        char target = postfix.at(i);

        if(target >= '0' && target <= '9')
        {
            int subTarget = (int)target-48;
            result.push(subTarget);
        }
        else
        {
            int second = result.top();
            result.pop();
            int first = result.top();
            result.pop();

            if(target == '+')
                result.push(first + second);
            else if(target == '*')
                result.push(first * second);
        }

    }

    return result.top();
}
