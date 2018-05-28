#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define MAX_VALUE 10000*3000

pair<int,int> minChapters(vector<int>& chapters, vector<pair<int,int> >& cache, int start);

int main()
{
    freopen("input.txt","r",stdin);

    int testSize;
    cin >> testSize;

    for(int t = 0; t < testSize; t++)
    {
        int k;
        cin >> k;

        vector<int> chapters(k,0);
        vector<pair<int,int> > cache(k, make_pair(MAX_VALUE,MAX_VALUE));
        // first : sum of two value
        // second : accum..value

        for(int i = 0; i < k; i++)
            cin >> chapters[i];

        pair<int,int> answer = minChapters(chapters, cache, 0);

        for(int i = 0; i < cache.size(); i++)
            cout << i << " : " << cache[i].second <<endl;

        cout << "#" << t+1 << " " << answer.second << endl;
    }

    return 0;
}

pair<int,int> minChapters(vector<int>& chapters, vector<pair<int,int> >& cache, int start)
{
    int chapterSize = chapters.size();

    pair<int,int>& answer = cache[start];
    if(start == chapterSize - 1)
        answer.first = answer.second = chapters[start];
    else if(start == chapterSize - 2)
        answer.first = answer.second = chapters[start] + chapters[start+1];
    else
    {
        if(answer.second == MAX_VALUE)
        {
            pair<int,int> target1 = minChapters(chapters,cache,start+1);
            pair<int,int> target2 = minChapters(chapters,cache,start+2);

            int sumTarget1 = chapters[start] + target1.first + target1.second;
            int sumTarget2 = chapters[start] + chapters[start+1] + target2.first + target2.second;

            if(sumTarget1 <= sumTarget2)
            {
                answer.first = chapters[start] + target1.first;
                answer.second = sumTarget1;
            }
            else
            {
                answer.first = chapters[start] + chapters[start+1] + target2.first;
                answer.second = sumTarget2;
            }
        }
    }

    return answer;
}
