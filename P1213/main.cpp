#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define TEST_CASES 10

int countSubString(string sentence, string target);

int main()
{
    freopen("input.txt","r",stdin);

    for(int i = 0; i < TEST_CASES; i++)
    {
        int test;
        string target;
        string sentence;

        cin >> test;
        cin >> target;
        cin>> sentence;

        int result = countSubString(sentence,target);

        cout << "#" << test << " " << result << endl;
    }
    return 0;
}

int countSubString(string sentence, string target)
{
    size_t pos_find = 0;
    int result = 0;

    while(pos_find != string::npos)
    {
        pos_find = sentence.find(target,pos_find);

        if(pos_find == string::npos)
            break;
        pos_find = pos_find + 1;
        if(pos_find >= sentence.size() )
            break;
        result++;
    }

    return result;
}
