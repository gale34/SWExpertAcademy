#include <iostream>
#include <cstdio>
#include <vector>

#define PASSWORD_SIZE 8

using namespace std;

void getPassword(vector<int>& numbers);

int main()
{
    freopen("input.txt","r",stdin);

    for(int i = 0; i < 10; i++)
    {
        int testCase;
        cin >> testCase;

        vector<int> numbers;

        for(int j = 0; j < PASSWORD_SIZE; j++)
        {
            int temp;
            cin >> temp;
            numbers.push_back(temp);
        }

        getPassword(numbers);

        cout << "#" << testCase;
        for(int j = 0; j < PASSWORD_SIZE; j++)
            cout << " " << numbers[j];
        cout << endl;
    }

    return 0;
}

void getPassword(vector<int>& numbers)
{
    int target = 0;
    bool isZero = false;

    while(!isZero)
    {
        for(int i = 0; i < 5; i++)
        {
            numbers[target] -= i+1;

            if(numbers[target] <= 0)
            {
                numbers[target] = 0;
                isZero = true;
            }

            target = (target + 1)%PASSWORD_SIZE;

            if(isZero)
                break;
        }
    }

    vector<int> result(PASSWORD_SIZE,0);
    for(int i = 0; i < 8; i++)
        result[i] = numbers[(target+i)%PASSWORD_SIZE];

    numbers = result;
}
