#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int getMostCommonNumber(vector<int> students);

int main()
{
    freopen("input.txt","r",stdin);

    for(int i = 0; i < 10; i++)
    {
        int test;
        vector<int> students;

        cin >> test;

        for(int j = 0; j < 1000; j++)
        {
            int temp;
            cin >> temp;

            students.push_back(temp);
        }

        int result = getMostCommonNumber(students);

        cout << "#" << test << " " << result << endl;
    }

    return 0;
}

int getMostCommonNumber(vector<int> students)
{
    int score[101] = {};
    int maxCommonTimes = 0;
    int result;

    for(vector<int>::iterator it = students.begin(); it != students.end(); it++)
        score[*it]++;

    for(int i = 0; i < 101; i++)
    {
        if(maxCommonTimes <= score[i])
        {
            maxCommonTimes = score[i];
            result = i;
        }
    }

    return result;
}
