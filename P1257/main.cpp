#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<string> splitSubCombiWord(string word);
int main()
{
    freopen("input.txt","r",stdin);

    int testCase;
    cin >> testCase;

    for(int t = 0; t < testCase; t++)
    {
        int order;
        cin >> order;

        string word;
        cin >> word;

        vector<string> result = splitSubCombiWord(word);

        cout << "#" << t+1 << " ";
        if(order > result.size())
            cout << "none" << endl;
        else
            cout << result[order-1] << endl;
    }

    return 0;
}

vector<string> splitSubCombiWord(string word)
{
    vector<string> splitWord;

    int wordSize = word.size();

    for(int i = 0; i < wordSize; i++)
    {
        for(int j = wordSize-i; j >= 0; j--)
            splitWord.push_back(word.substr(i,j));
    }

    sort(splitWord.begin(), splitWord.end());

    for(vector<string>::iterator it = splitWord.begin(); it != splitWord.end();)
    {
        vector<string>::iterator nextIt = it+1;

        if(nextIt == splitWord.end())
            break;

        if((*it).compare(*nextIt) == 0 || (*it).compare("") == 0)
            it = splitWord.erase(it);
        else
            it++;
    }
    return splitWord;
}
