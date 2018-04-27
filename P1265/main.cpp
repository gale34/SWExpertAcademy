#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

long long maxTalent(int talent, int bundle);

int main()
{
    freopen("input.txt","r",stdin);

    int testCase;
    cin >> testCase;

    for(int i = 0; i < testCase; i++)
    {
        int talent, bundle;
        cin >> talent >> bundle;

        long long result = maxTalent(talent,bundle);

        cout << "#" << i+1 << " " << result << endl;
    }

    return 0;
}

long long maxTalent(int talent, int bundle)
{
    int portion = talent / bundle;
    int rest = talent % bundle;

    vector<int> talentBundle(bundle,portion);

    for(int i = 0; i < bundle; i++)
    {
        if(rest == 0)
            break;
        talentBundle[i]++;
        rest--;
    }

    long long result = 0;
    for(int i = 0; i < bundle; i++)
    {
        if(result == 0)
            result = talentBundle[i];
        else
            result *= talentBundle[i];
    }

    return result;
}
