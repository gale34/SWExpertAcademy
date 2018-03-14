#include <iostream>
#include <cstdio>

using namespace std;

#define LENGTH 100

int getMaxValue(int arr[][LENGTH]);

int main()
{
    freopen("input.txt", "r", stdin);

    for(int i = 0 ; i < 10; i++)
    {
        int test;
        int arr[LENGTH][LENGTH];
        cin >> test;

        for(int i = 0; i < LENGTH; i++)
            for(int j = 0; j < LENGTH; j++)
                cin >> arr[i][j];

        int result = getMaxValue(arr);

        cout << "#" << test << " " << result << endl;
    }
    return 0;
}

int getMaxValue(int arr[][LENGTH])
{
    int result = 0;
    int sum = 0;

    for(int i = 0; i < LENGTH; i++)
    {
        sum = 0;
        for(int j = 0; j < LENGTH; j++)
            sum += arr[i][j];

        result = max(sum,result);
    }

    for(int j = 0; j < LENGTH; j++)
    {
        sum = 0;
        for(int i = 0; i < LENGTH; i++)
            sum += arr[i][j];

        result = max(sum,result);
    }

    sum = 0;
    for(int i = 0; i < LENGTH; i++)
        sum += arr[i][i];

    result = max(sum, result);

    sum = 0;
    for(int i = 0; i < LENGTH; i++)
        sum += arr[i][LENGTH-1-i];

    result = max(sum, result);

    return result;
}
