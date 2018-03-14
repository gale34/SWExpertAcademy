#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int getDiffAftreFlatting(int dump, vector<int> boxes);
int getMinPt(int minPt,int boxHeight[]);
int getMaxPt(int maxPt,int boxHeight[]);

int main()
{
    freopen("input.txt","r",stdin);

    for(int i = 0; i < 10; i++)
    {
        int dump;
        vector<int> boxes;

        cin >> dump;

        for(int j = 0; j < 100; j++)
        {
            int temp;
            cin >> temp;

            boxes.push_back(temp);
        }

        int result = getDiffAftreFlatting(dump, boxes);
        cout << "#" << i+1 << " " << result << endl;
    }

    return 0;
}

int getDiffAftreFlatting(int dump, vector<int> boxes)
{
    int diff = 0;

    int boxHeight[101] = {};

    for(vector<int>::iterator it = boxes.begin(); it != boxes.end(); it++)
        boxHeight[*it]++;

    int minPt = 1;
    int maxPt = 100;

    minPt = getMinPt(minPt,boxHeight);
    maxPt = getMaxPt(maxPt,boxHeight);

    while(dump > 0)
    {
        if(maxPt - minPt <= 1)
            break;
        boxHeight[maxPt]--;
        boxHeight[maxPt-1]++;

        boxHeight[minPt]--;
        boxHeight[minPt+1]++;
        dump--;

        if(boxHeight[maxPt] == 0)
            maxPt = getMaxPt(maxPt,boxHeight);
        if(boxHeight[minPt] == 0)
            minPt = getMinPt(minPt,boxHeight);
    }

    diff = maxPt - minPt;

    return diff;
}

int getMinPt(int minPt,int boxHeight[])
{
    for(int i = minPt; i < 101; i++)
    {
        if(boxHeight[i] != 0)
        {
            minPt = i;
            break;
        }
    }

    return minPt;
}

int getMaxPt(int maxPt,int boxHeight[])
{
    for(int i = maxPt; i >= 0; i--)
    {
        if(boxHeight[i] != 0)
        {
            maxPt = i;
            break;
        }
    }
    return maxPt;
}
