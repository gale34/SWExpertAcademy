#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define MAX_VALUE 100000*3000

void minChapters(int* accumChapters, int* minIndex, int** cache,int numSize);

int main()
{
    freopen("input.txt","r",stdin);

    int testSize;
    cin >> testSize;

    for(int t = 0; t < testSize; t++)
    {
        int k;
        cin >> k;

        int* accumChapters = new int[k+1];
        int* minIndex = new int[k+1];
        int** cache = new int*[k+1];

        for(int i = 0; i <= k; i++)
        {
            accumChapters[i] = 0;
            minIndex[i] = 0;

            cache[i] = new int[k+1];
            for(int j = 0; j <= k; j++)
                cache[i][j] = MAX_VALUE;

            cache[i][i] = MAX_VALUE;
            if(i > 0)
            {
                cache[i][i-1] = 0;
                cache[i-1][i] = 0;
            }
        }

        for(int i = 1; i <= k; i++)
        {
            cin >> accumChapters[i];
            accumChapters[i] += accumChapters[i-1];
            minIndex[i-1] = i;
        }

        minChapters(accumChapters,minIndex,cache,k);

        int answer = cache[0][k];

        cout << "#" << t+1 << " " << answer << endl;

        delete accumChapters;
        delete minIndex;
        for(int i = 0; i < k; i++)
            delete cache[i];
        delete cache;

    }

    return 0;
}

void minChapters(int* accumChapters, int* minIndex, int** cache, int numSize)
{

    for(int len = 2; len <= numSize; len++)
    {
        for(int i = 0, j = len; j <= numSize; i++, j++)
        {
            int start = minIndex[i];
            int finish = minIndex[i+1];

            for(int k = start; k <= finish; k++)
            {
                int temp = cache[i][k] + cache[k][j];
                if(cache[i][j] > temp)
                {
                    cache[i][j] = temp;
                    minIndex[i] = k;
                }
            }
            cache[i][j] += accumChapters[j] - accumChapters[i];
        }
    }

    return ;
}
