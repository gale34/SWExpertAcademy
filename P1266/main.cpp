#include <iostream>
#include <vector>
#include <cstdio>

#define CACHE_PRIME_SIZE 19

using namespace std;

bool cachePrimeNumber[CACHE_PRIME_SIZE];

vector<double> chanceBePrimeNumber(int skillOfMaster, int makingCount);
bool isPrimeNumber(int target);

int main()
{
    freopen("input.txt","r",stdin);
    int testCase;
    cin >> testCase;

    for(int i = 0; i < CACHE_PRIME_SIZE; i++)
        cachePrimeNumber[i] = isPrimeNumber(i);

    cout << fixed;
    cout.precision(6);
    for(int t = 0; t < testCase; t++)
    {
        int skillOfMasterA, skillOfMasterB;
        cin >> skillOfMasterA >> skillOfMasterB;

        vector<double> chanceToMakePerfectA = chanceBePrimeNumber(skillOfMasterA, CACHE_PRIME_SIZE-1);
        vector<double> chanceToMakePerfectB = chanceBePrimeNumber(skillOfMasterB, CACHE_PRIME_SIZE-1);

        double noPrimeMakingA = 0;
        double noPrimeMakingB = 0;

        for(int i = 0; i < CACHE_PRIME_SIZE; i++)
        {
            if(cachePrimeNumber[i] == 0)
            {
                noPrimeMakingA += chanceToMakePerfectA[i];
                noPrimeMakingB += chanceToMakePerfectB[i];
            }
        }

        double result = 1 - (noPrimeMakingA * noPrimeMakingB);

        cout << "#" << t+1 << " " << result << endl;
    }

    return 0;
}

vector<double> chanceBePrimeNumber(int skillOfMaster, int makingCount)
{
    vector<double> chanceToMaking(CACHE_PRIME_SIZE,0);

    double probMakingPerfect = (double)skillOfMaster/100;
    double probMakingFail = 1-probMakingPerfect;

    if(makingCount == 1)
    {
        chanceToMaking[0] = probMakingFail;
        chanceToMaking[1] = probMakingPerfect;
    }
    else
    {
        vector<double> chanceToMakeingBeforeCount = chanceBePrimeNumber(skillOfMaster, makingCount - 1);

        for(int i = 0; i < makingCount; i++)
        {
            chanceToMaking[i+1] += chanceToMakeingBeforeCount[i] * probMakingPerfect;
            chanceToMaking[i] += chanceToMakeingBeforeCount[i] * probMakingFail;
        }
    }

    return chanceToMaking;
}

bool isPrimeNumber(int target)
{
    if(target == 0 || target == 1)
        return false;

    for(int i = 2; i <= target/2; i++)
    {
        if(target % i == 0)
            return false;
    }

    return true;
}
