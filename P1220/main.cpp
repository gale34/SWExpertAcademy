#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

#define N_POLE 1
#define S_POLE 2

using namespace std;

int getDeadLock(int** table, int sideSize);

int main()
{
    freopen("input.txt","r",stdin);

    for(int i = 0; i < 10; i++)
    {
        int sideSize;
        cin >> sideSize;

        int** table = new int*[sideSize];
        for(int j = 0; j < sideSize; j++)
        {
            table[j] = new int[sideSize];
            memset(table[j],0,sizeof(int)*sideSize);
        }

        for(int j = 0; j < sideSize; j++)
            for(int k = 0; k < sideSize; k++)
                cin >> table[j][k];

        int result = getDeadLock(table, sideSize);

        cout << "#" << i+1 << " " << result << endl;

        for(int j = 0; j < sideSize; j++)
            delete table[j];
        delete table;
    }

    return 0;
}

int getDeadLock(int** table, int sideSize)
{
    int result = 0;

    for(int i = 0; i < sideSize; i++)
    {
        vector<int> magneticBody;

        for(int j = 0; j < sideSize; j++)
        {
            if(table[j][i] != 0)
                magneticBody.push_back(table[j][i]);
        }

        for(vector<int>::iterator it = magneticBody.begin(); it != magneticBody.end();)
        {
            if(*it != 2)
                break;
            else
                it = magneticBody.erase(it);
        }

        for(vector<int>::reverse_iterator rit = magneticBody.rbegin(); rit != magneticBody.rend(); rit++)
        {
            if(*rit != 1)
                break;
            else
                magneticBody.erase(rit.base()-1);
        }

        for(int j = 0; j < magneticBody.size()-1; j++)
        {
            if(j+1 != magneticBody.size() && magneticBody[j] == 1 && magneticBody[j+1] == 2)
                result++;
        }

    }

    return result;
}
