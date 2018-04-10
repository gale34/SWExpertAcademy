#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

int cost[3];
int main()
{
    freopen("input.txt","r",stdin);

    int testCase;
    cin >> testCase;

    for(int i = 0; i < 3; i++)
        cost[i] = floor((double)pow(i+1,2)/2 + (double)2*(i+1)/3 + 1);

    for(int t = 0; t < testCase; t++)
    {
        int width, fragment;
        cin >> width;
        cin >> fragment;

        vector<vector<bool> > metal(width);
        for(int i = 0; i < width; i++)
        {
            vector<bool> temp(width,false);
            metal[i] = temp;
        }

        for(int i = 0; i < fragment; i++)
        {
            int x, y;
            cin >> x >> y;
        }
    }

    return 0;
}
