#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

int getHits(vector<pair<int, int> >& robots, int target);
int getSecondValue(vector<int>& hits,int k);
int gcd(int p, int q);

int main()
{
    freopen("input.txt","r",stdin);

    int testCase;
    cin >> testCase;

    for(int t = 0; t < testCase; t++)
    {
        int r, n, k;
        cin >> r >> n >> k;

        vector<pair<int, int> > robots;

        for(int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;

            robots.push_back(make_pair(x,y));
        }

        vector<int> hits(n,0);
        int sum = 0;

        for(int i = 0 ; i < hits.size(); i++)
        {
            hits[i] = getHits(robots, i);
            sum += hits[i];
        }

        int sum2 = getSecondValue(hits,k);

        cout << "#" << t+1 << " " << sum << " " << sum2 << endl;
    }

    return 0;
}

int getHits(vector<pair<int, int> >& robots, int target)
{
    vector<pair<int, int> > hitsOfTarget;
    for(int i = 0; i < robots.size(); i++)
    {
        if(i == target)
            continue;

        pair<int, int> minVector;
        minVector.first = robots[target].first - robots[i].first;
        minVector.second = robots[target].second - robots[i].second;

        if(minVector.first == 0)
            minVector.second /= abs(minVector.second);
        else if(minVector.second == 0)
            minVector.first /= abs(minVector.first);
        else
        {
            int gcdValue = gcd(abs(minVector.first),abs(minVector.second));

            minVector.first /= gcdValue;
            minVector.second /= gcdValue;
        }

        bool isFind = false;
        for(int j = 0; j < hitsOfTarget.size(); j++)
        {
            pair<int, int> hitTarget = hitsOfTarget[j];

            if(hitTarget == minVector)
            {
                isFind = true;
                break;
            }
        }
        if(!isFind)
            hitsOfTarget.push_back(minVector);
    }

    return hitsOfTarget.size();
}

int getSecondValue(vector<int>& hits,int k)
{
    int hitSize = hits.size();
    hits.resize(hitSize*2);

    vector<int> arrayC(hitSize+1,0);

    for(int i = 1; i <= hitSize; i++)
    {
        for(int j = 1; j <= hitSize; j++)
        {
            hits[j-1] = ((hits[j-1]*k + j) % hitSize) + 1;
            hits[hitSize+j-1] = ((hits[j-1]*j + k) % hitSize) + 1;
        }

        sort(hits.begin(),hits.end());

        vector<int> arrayB(2*hitSize + 1,1);

        for(int j = 1; j <= hitSize*2; j++)
            arrayB[j] = ((arrayB[j-1] * hits[j-1] + j) % hitSize) + 1;

        arrayC[i] = arrayB[hitSize*2];
    }

    int sum = 0;
    for(int i = 0; i <= hitSize; i++)
        sum += arrayC[i];

    return sum;
}
int gcd(int p, int q)
{
    if(p < q)
        return gcd(q,p);
    else if(q == 0)
        return p;
    else
        return gcd(q, p % q);
}
