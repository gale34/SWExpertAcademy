#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

struct plat
{
    int x;
    int y;
    int cover;
};

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

            temp[x][y] = true;
        }
    }

    return 0;
}

int getMinCost(int x, int y, int width, vector<vector<bool> >& metal)
{
    bool isFind = false;

    int targetX = x;
    int targetY = y;

    for(int i = x; i < width; i++)
    {
        for(int j = y; j < width; j++)
        {
            int countFrags = countFragment(i,j,metal);

            if(countFrags != 0)
                isFind = true;



            if(isFind)
                break;
        }

        if(isFind)
            break;
    }

    if(metal[x][y] == true)
}

int countFragment(int x, int y, int width, vector<vector<bool> >& metal)
{
    int result = 0;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int targetX = x+i;
            int targetY = y+j;

            if(targetX >= 0 && targetX < width && targetY >= 0 && targetY < width && metal[targetX][targetY] == true)
                result++;
        }
    }

    return result;
}
