#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

void printValues(vector<int> values);

string intToString(int value);
int stringToInt(string value);

int main()
{
    freopen("input.txt","r",stdin);

    int testCase;

    cin >> testCase;

    for(int i = 0; i < testCase; i++)
    {
        int testSize;
        string temp;
        vector<int> values;

        cin >> temp;
        cin >> testSize;

        for(int j = 0; j < testSize; j++)
        {
            cin >> temp;

            int realValue = 0;

            realValue = stringToInt(temp);
            values.push_back(realValue);
        }

        cout << "#" << i+1 << endl;
        printValues(values);
        cout << endl;

    }
    return 0;
}

void printValues(vector<int> values)
{
    sort(values.begin(), values.end());
    for(int i = 0; i < values.size(); i++)
        cout << intToString(values[i]);
}

string intToString(int value)
{
    switch(value)
    {
    case 0:
        return "ZRO ";
    case 1:
        return "ONE ";
    case 2:
        return "TWO ";
    case 3:
        return "THR ";
    case 4:
        return "FOR ";
    case 5:
        return "FIV ";
    case 6:
        return "SIX ";
    case 7:
        return "SVN ";
    case 8:
        return "EGT ";
    case 9:
        return "NIN ";
    }
}
int stringToInt(string value)
{
    if(value.compare("ZRO") == 0)
        return 0;
    else if(value.compare("ONE") == 0)
        return 1;
    else if(value.compare("TWO") == 0)
        return 2;
    else if(value.compare("THR") == 0)
        return 3;
    else if(value.compare("FOR") == 0)
        return 4;
    else if(value.compare("FIV") == 0)
        return 5;
    else if(value.compare("SIX") == 0)
        return 6;
    else if(value.compare("SVN") == 0)
        return 7;
    else if(value.compare("EGT") == 0)
        return 8;
    else if(value.compare("NIN") == 0)
        return 9;
}
